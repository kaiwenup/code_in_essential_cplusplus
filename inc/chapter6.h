#ifndef _CHAPTER6_H
#define _CHAPTER6_H

#include <iostream>
using namespace std;

/*类的声明*/
template <typename elemType>
class BinaryTree;

template <typename elemType>
class BTnode;



template < typename valType >
class BTnode{
    friend class BinaryTree<valType>;
public:
    BTnode( const valType &val );

    static void lchild_leaf( BTnode *leaf, BTnode *subtree );
    void insert_value( const valType & );
    void remove_value( const valType &, BTnode *& );
    bool find_value( const valType &val ) const ;
    
  
    void preorder( BTnode *pt, ostream &os = cout ) const ;
    void ineorder( BTnode *pt, ostream &os = cout ) const ;
    void postorder( BTnode *pt, ostream &os = cout ) const ;

    const valType& value() const { return _val;}
    int occurs() const { return _cnt; }


private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;

    BTnode( const BTnode& );
    void display_val(BTnode *pt, ostream &os = cout) const;

    BTnode&  operator =( const BTnode& );
};

template<typename valType>
inline BTnode<valType>::BTnode( const valType &val )
    :_val( val )
    {
        _cnt =  1;
        _lchild = _rchild = 0;
    }


template< typename valType>
inline void BTnode<valType>::insert_value( const valType &val)
{
    if( val == _val){
        _cnt ++;
        return;
    }
    if( val < _val ){
        if( ! _lchild ){
            _lchild = new BTnode( val );
        } 
        else{
            _lchild->insert_value( val );
        }
    }
    else{
        if( ! _rchild ){
            _rchild = new BTnode( val );
        } 
        else{
            _rchild->insert_value( val );
        }
        
    }
}

template <typename valType>
bool 
BTnode<valType>::
find_value( const valType &val ) const
{
    if ( val == _val )
       return true; 

	if ( val < _val ){
		if ( ! _lchild )
			 return false;
		else return _lchild->find_value( val );
	}
	else {
		if ( ! _rchild )
			 return false;
		else return _rchild->find_value( val );
	}
}


template <typename valType>
inline void BTnode<valType>::display_val( BTnode *pt, ostream &os ) const
{
       os << pt->_val;
       if ( pt->_cnt > 1 )
            os << "( " << pt->_cnt << " ) "; 
       else os << ' ';
}



template< typename valType>
inline void BTnode<valType>::lchild_leaf( BTnode *leaf, BTnode *subtree )
{   
    while( subtree->_lchild )
        subtree = subtree->_lchild;

    subtree->_lchild = leaf;

}

template< typename valType>
inline void BTnode<valType>::remove_value( const valType &val, BTnode *& prev)
{
    if( val < _val )
    {
        if( ! _lchild )
            return;
        else   
            _lchild->remove_value( val, _lchild );
    }
    else if( val > _val )
    {
        if( ! _rchild )
            return;
        else    
            _rchild->remove_value( val, _rchild );
    }
    else
    {
        if( _rchild )
        {
            prev = _rchild;
            if( _lchild ){
                if( ! prev->_lchild ){
                    prev->_lchild = _lchild;
                }   
                else{
                    BTnode<valType>::lchild_leaf( _lchild, prev->_lchild );
                }
            }           
        }
        else
            prev = _lchild;
       
        delete this;
    }
}

template< typename valType>
inline void BTnode<valType>::preorder( BTnode *pt, ostream &os ) const
{
    if( pt )
    {
        display_val( pt, os );
        if( pt->_lchild ) 
            preorder( pt->_lchild, os);

        if( pt->_rchild )
            preorder( pt->_rchild, os);
    }
}

template< typename valType>
inline void BTnode<valType>::ineorder( BTnode *pt, ostream &os ) const
{
    if( pt )
    {
        
        if( pt->lchild ) 
            inorder( pt->_lchild, os);

        display_val( pt, os );

        if( pt->_rchild )
            inorder( pt->_rchild, os);
    }
}

template< typename valType>
inline void BTnode<valType>::postorder( BTnode *pt, ostream &os ) const
{
    if( pt )
    {
        
        if( pt->lchild ) 
            postorder( pt->_lchild, os);

        if( pt->_rchild )
            postorder( pt->_rchild, os);

        display_val( pt, os );
    }
}


template <typename elemType>
class BinaryTree{
    friend class BTnode<elemType>;
    // friend ostream& operator<< ( ostream & , const BinaryTree<elemType> & ); //不需要在这边再声明friend
public:
    BinaryTree();
    BinaryTree( const BinaryTree& );
    ~BinaryTree();

    BinaryTree& operator=( const BinaryTree& );  //这里只是一个声明，需要在其他地方定义这个函数

    bool empty() { return _root == 0; }
    void clear() { if( _root ){ clear( _root ); _root = 0; } }
    bool find( const elemType& ) const;
    void insert( const elemType & );
    void remove( const elemType & );
    // void remove_root();
    // void print( ostream &os = *_current_os );
    void inorder( ostream &os = *_current_os )   const { _root->inorder( _root, os ); }
    void postorder( ostream &os = *_current_os ) const { _root->postorder( _root, os ); }
    void preorder( ostream &os = *_current_os )  const { _root->preorder( _root, os ); }

    ostream& print( ostream &os = *_current_os, 
                    void (BinaryTree<elemType>::*traversal)( ostream& ) const = &BinaryTree<elemType>::preorder) const;

    static void current_os( ostream *os = &cout ) {  if(os) {_current_os = os;} }  // 注意这里是 &cout
    static ostream* os() { return _current_os; }
private:
    BTnode<elemType> *_root;
    static ostream *_current_os; // 还需要在其他地方定义一下,是不是所有的static都是要在class外定义一下

    void clear( BTnode<elemType>* );
    void copy( BTnode<elemType>*tar, BTnode<elemType>*src );
    void remove_root(); 
};

/**static 在类说明之后还需要在其他地方再定义一下？**/
template <typename elemType>
ostream *BinaryTree<elemType>::_current_os = &cout;


template <typename elemType >
inline BinaryTree<elemType>::BinaryTree()
    : _root( 0 )
    {}

template<typename elemType>
inline BinaryTree<elemType>::BinaryTree( const BinaryTree &rhs)
{
    copy( _root, rhs._root );
}

template <typename elemType>
inline bool 
BinaryTree<elemType>::
find( const elemType &elem ) const
{
	return  ! _root 
		    ? false
			: _root->find_value( elem );
}


template<typename elemType>
inline BinaryTree<elemType>::~BinaryTree()
{
    clear();
}

template<typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::operator=( const BinaryTree &rhs )
{
    if( this != &rhs )
    {
        clear();
        copy( _root, rhs._root );
    }
}

template< typename elemType>
inline void BinaryTree<elemType>::clear( BTnode<elemType> *pt )
{
    if( pt )
    {
        clear( pt->_lchild );
        clear( pt->_rchild );
        delete pt;

    }
}

template< typename elemType>
inline void
BinaryTree<elemType>::insert( const elemType &elem )
{
    if( ! _root )
    {
        _root = new BTnode<elemType>( elem );
    }
    else
        _root->insert_value( elem );

}

template< typename elemType>
inline void
BinaryTree<elemType>::remove( const elemType &elem )
{
    if( _root )
    {
        if( _root->_val == elem){
            (*BinaryTree<elemType>::os()) << "BinaryTree::remove: root( " << elem << " )\n";
            remove_root(); // 根节点的移除以特例处理
        }
            
        else 
            _root->remove_value( elem, _root );

    }

}

template< typename elemType>
void BinaryTree<elemType>::remove_root()
{
    if( ! _root )
        return;

    BTnode<elemType> *tmp = _root;
    if( _root->_rchild )
    {
        _root = _root->_rchild;

        //将左节点移到右节点的左子树的底部

        if( tmp->_rchild ) 
        {
            BTnode<elemType> *lc = tmp->_lchild;
            BTnode<elemType> *newlc = _root->_lchild;
            if( ! newlc )
                _root->lchild = lc;
        
        else
            BTnode<elemType>::lchild_leaf(lc, newlc);

        }

    }
    else
        _root = _root->lchild();

    delete tmp;
}




template< typename elemType>
ostream& BinaryTree<elemType>::
print( ostream &os, 
        void (BinaryTree::*traversal)( ostream&) const ) const
{
    (this->*traversal)( os );
    return os;
}

template <typename elemType>
inline ostream& operator<< ( ostream &os, const BinaryTree<elemType> &bt)
{
    os << "Tree: "<< endl;
    bt.print();
    return os;
}



#endif