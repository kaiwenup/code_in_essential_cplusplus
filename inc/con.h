#ifndef _CON_H_
#define _CON_H_


#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

/**！！！ class类的定义以及内联（inline）函数可以放在头文件中，但是类内成员函数的定头文件定义
 *接放在头文件会报错，应该放在同名.cpp文件之中
 * 头文件只放函数声明， 类定义， inline函数， 变量定义。(类定义的时候注意最后的括号加  ; )
 *
 * multiple definition of `Triangular::display()'
 * ./obj/con.o:con.cpp:(.text+0x0): first defined here
 **/

using namespace std;
/**
 * 自己写的头文件放这边**/
#include "debug_switch.h"

/** definition of class Triangular_iterator**/

class Triangular_iterator
{
    // friend class Triangular;
public:
    Triangular_iterator( int index )
        : _index( index-1 ){}
    
    bool operator==( const Triangular_iterator& ) const;
    bool operator!=( const Triangular_iterator& ) const;
    int  operator*() const;
    Triangular_iterator& operator++();  //前置（prefix）版
    Triangular_iterator  operator++( int );  //后置（postfix）版


private:
    void check_integrity() const;
    int _index;
};

/** definition of class Triangular**/

class Triangular{
    friend class Triangular_iterator;
public:
    Triangular(){
        _length = 1;
        _beg_pos = 1;
        _next = 0;
    }  //default constructor
    Triangular( int len ){
        _length = len > 0 ? len : 1;
        _beg_pos = 1;
        _next = 0;
    }
    Triangular( int len, int bp ){
        _length = len > 0 ? len : 1;
        _beg_pos = bp > 0 ? bp : 1;
        _next = _beg_pos - 1; 
    }

    
    typedef Triangular_iterator iterator;
    
    Triangular_iterator begin() const
    {
        return Triangular_iterator( _beg_pos );

    }

    Triangular_iterator end() const
    {
        return Triangular_iterator( _beg_pos+_length );
    }
    
    

    // const member function
    int length()  const { return _length; }
    int beg_pos() const { return _beg_pos; }
    int elem( int pos ) const {return _elems[ pos - 1 ];}
    bool next( int &value ) const{
        if( _next < _beg_pos + _length -1 )
        {
            value = _elems[ _next++ ];
            return true;
        }

    return false;
    }
    void next_reset() const { _next = _beg_pos - 1; }

    // non-const static member function( statement ) 
    static void gen_elems_to_value( int value );
    static bool is_elem( int value );
    static void gen_elements( int length );
    static void display( int length, int beg_pos, ostream &os = cout );
    
    /**
     * 正常情况下需要先定义一个对象才能调用成员函数，
     * 但是如果如果想直接引用，可以声明函数为 static 静态
     * **/
    // non-const member function( statement ) 
    // void display(); // 老版本声明
   
    Triangular& copy( const Triangular &rhs );
    

    // non-const member function( definition ) 


    /**测试用**/
    void push( int elem) {
        _elems.push_back( elem );
    }

    bool empty(){
        return _elems.empty();
    }

    int peek( int &elem ){
        elem = _elems.back();
        return elem;
    }

    

private:
    int _length;
    int _beg_pos;
    mutable int _next;
    static const int _max_elems = 1024;

    static vector<int> _elems;
};

/** 错误做法 头文件不应该有函数的定义
void
Triangular::display()
{
    cout << "length:" << _length
        << " beg_pos:" << _beg_pos << endl;
}
**/

// dummy for now
class iterator_overflow{};

inline bool Triangular_iterator::
    operator==( const Triangular_iterator &rhs ) const
                { return _index == rhs._index; }

inline bool Triangular_iterator::
    operator!= ( const Triangular_iterator &rhs) const
                { return !( *this == rhs ); }
/** *this == rhs调用的是inline bool Triangular_iterator::
 *  operator==( const Triangular_iterator &rhs ) const
 * **/

inline int Triangular_iterator::
    operator*() const
{
    check_integrity();
    return Triangular::_elems[ _index ];
}


inline void Triangular_iterator::
check_integrity() const
{
    
    if( _index >= Triangular::_max_elems )
        throw iterator_overflow();
    
    if ( _index > Triangular::_elems.size() )
        Triangular::gen_elements( _index );
           
   
}

inline Triangular_iterator& Triangular_iterator::
        operator++()
{ //前置版本
    ++_index;
    check_integrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::
        operator++( int )
{//后置版本
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}


/**----------------------------------------------------------**/
// definition of class Matrix

/**matrix copy assignment operator **/

class Matrix{
    // friend class Matrix_iterator;
public: 

    // typedef Matrix_iterator iterator;
    Matrix& operator=( const Matrix & );
    Matrix( int row, int col)
        : _row( row ), _col( col)

    {
        _pmat = new double[ row * col];
    }

    Matrix( const Matrix &rhs )
        : _row( rhs._row ), _col( rhs._col )
    {
        int elem_cnt = _row * _col;
        _pmat = new double[ elem_cnt ];

        for( int ix = 0; ix < elem_cnt; ix++ )
        {
            _pmat[ ix ] = rhs._pmat[ ix ];
        }
    }
    void display(){
         for( int ix = 0; ix < _row * _col; ix++ )
        {
            cout << _pmat[ix] << " ";
        }
    }
    ~Matrix()
    {
        delete [] _pmat;
    }

private:
    int _row, _col;
    double* _pmat;
};

/**注意和Triangular_iterator定义的区别
 * Triangular_iterator是自己单独定义了一个class，然后与Triangular建立联系
 * 而Matrix中的operator是定义在class Matrix中的
 * **/
inline Matrix&  Matrix::operator=( const Matrix &rhs )
{
    if( this != &rhs )
    {
        _row = rhs._row;
        _col = rhs._col;
        int elem_cnt = _row * _col;
        delete [] _pmat;
        _pmat = new double[ elem_cnt ];
        for( int ix = 0; ix < elem_cnt; ++ix)
        {
            _pmat = rhs._pmat;
        }

    }

    return *this;
}


#endif