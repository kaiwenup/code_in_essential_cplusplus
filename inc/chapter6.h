#ifndef _CHAPTER6_H
#define _CHAPTER6_H

#include <iostream>
using namespace std;

/*类的声明*/
template <typename elemType>
class BinaryTree;

template <typename elemType>
class BTnode;


template <typename elemType>
inline ostream& operator<< ( ostream &os, const BinaryTree<elemType> &bt)
{
    os << "Tree: "<< endl;
    bt.print();
    return os;

}


template < typename valType >
class BTnode{
    friend class BinaryTree<valType>;
public:
    BTnode( const valType &val );

    static void lchild_leaf( BTnode *leaf, BTnode *subtree );
    void insert_value( const valType & );
    void remove_value( const valType &, BTnode *& );
    
  
    void preorder( BTnode *pt, ostream &os = cout ) const ;
    void ineorder( BTnode *pt, ostream &os = cout ) const ;
    void postorder( BTnode *pt, ostream &os = cout ) const ;


private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;

    BTnode( const BTnode& );
    void display_val(BTnode *pt, ostream &os = cout) const;
};

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
inline void BTnode<valType>::display_val( BTnode *pt, ostream &os ) const
{
       os << pt->_val;
       if ( pt->_cnt > 1 )
            os << "( " << pt->_cnt << " ) "; 
       else os << ' ';
}


template<typename valType>
inline BTnode<valType>::BTnode( const valType &val )
    :_val( val )
    {
        _cnt =  1;
        _lchild = _rchild = 0;
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
friend ostream& operator<< ( ostream & , const BinaryTree<elemType> & );
public:
    BinaryTree();
    BinaryTree( const BinaryTree& );
    ~BinaryTree();

    BinaryTree& operator=( const BinaryTree& );

    bool empty() { return _root == 0; }
    void clear() { if( _root ){ clear( _root ); _root = 0; } }
    void insert( const elemType & );
    void remove( const elemType & );
    void remove_root();
    void print( ostream &os = cout );
    void inorder( ostream &os = cout )   const { _root->inorder( _root, os ); }
    void postorder( ostream &os = cout ) const { _root->postorder( _root, os ); }
    void preorder( ostream &os = cout )  const { _root->preorder( _root, os ); }
    
private:
    BTnode<elemType> *_root;

    void clear( BTnode<elemType>* );
    void copy( BTnode<elemType>*tar, BTnode<elemType>*src );
};



template <typename elemType >
inline BinaryTree<elemType>::BinaryTree()
    : _root( 0 )
    {}

template<typename elemType>
inline BinaryTree<elemType>::BinaryTree( const BinaryTree &rhs)
{
    copy( _root, rhs._root );
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
        _root = new BTnode<elemType>( elem );
    else
        _root->insert_value( elem );

}

template< typename elemType>
inline void
BinaryTree<elemType>::remove( const elemType &elem )
{
    if( _root )
    {
        if( _root->_val == elem)
            remove_root(); // 根节点的移除以特例处理
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



#endif