#ifndef _CON_H_
#define _CON_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//！！！ class类的定义以及内联（inline）函数可以放在头文件中，但是类内成员函数的定头文件定义
//直接放在头文件会报错，应该放在同名.cpp文件之中
// 头文件只放函数声明， 类定义， inline函数， 变量定义。
/**
 * multiple definition of `Triangular::display()'
 * ./obj/con.o:con.cpp:(.text+0x0): first defined here
 **/


// class Triangular Matrix

using namespace std;

// definition of class Triangular

class Triangular{
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

    // non-const member function( statement ) 
    void display();
    void gen_elems_to_value( int value );
    bool is_elem( int value );
    void gen_elements( int length );

    // non-const member function( definition ) 
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

    

    Triangular& copy( const Triangular &rhs );

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



/**----------------------------------------------------------**/
// definition of class Matrix

class Matrix{
public: 

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


#endif