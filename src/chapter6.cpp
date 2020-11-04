#include "chapter6.h"


// template<typename elemType>
// static ostream BinaryTree<elemType>::*_current_os;
/**函数只能目前只能定义在头文件，定义在cpp文件会报错**/
// template< typename valType>
// void BTnode<valType>::insert_value( const valType &val)
// {
//     if( val == _val){
//         _cnt ++;
//         return;
//     }
//     if( val < _val ){
//         if( ! _lchild ){
//             _lchild = new BTnode( val );
//         } 
//         else{
//             _lchild->insert_value( val );
//         }
//     }
//     else{
//         if( ! _rchild ){
//             _rchild = new BTnode( val );
//         } 
//         else{
//             _rchild->insert_value( val );
//         }
        
//     }
// }
// template< typename valType>
// void BTnode<valType>::preorder( BTnode *pt, ostream &os ) const
// {
//     if( pt )
//     {
//         display_val( pt, os );
//         if( pt->lchild ) 
//             preorder( pt->_lchild, os);

//         if( pt->_rchild )
//             preorder( pt->_rchild, os);
//     }
// }

// template< typename valType>
// void BTnode<valType>::ineorder( BTnode *pt, ostream &os ) const
// {
//     if( pt )
//     {
        
//         if( pt->lchild ) 
//             inorder( pt->_lchild, os);

//         display_val( pt, os );

//         if( pt->_rchild )
//             inorder( pt->_rchild, os);
//     }
// }

// template< typename valType>
// void BTnode<valType>::postorder( BTnode *pt, ostream &os ) const
// {
//     if( pt )
//     {
        
//         if( pt->lchild ) 
//             postorder( pt->_lchild, os);

//         if( pt->_rchild )
//             postorder( pt->_rchild, os);

//         display_val( pt, os );
//     }
// }