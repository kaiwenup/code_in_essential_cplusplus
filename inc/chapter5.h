#ifndef _CHAPTER5_H_
#define _CHAPTER5_H_
// #include "con.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

/**三层的类体系
 * ************************************************************************
 * **/
class LibMat{
public:
    LibMat(){ cout << "LibMat::LibMat() default constructor!\n"; }

    virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }
    virtual void print() const
    { cout << "LibMat::print() -- I am a LibMat object!\n"; }

};

class Book :public LibMat{
public:
    Book( const string &title, const string &author )
        : _title( title ), _author( author ){
            cout << "Book::Book( " << _title << ", "<< _author << " ) constructor\n";
        }

    virtual ~Book(){
        cout << "Book::~Book() destructor!\n";
    }

    virtual void print() const {
        cout << "Book::print() -- I am a Book object!\n"
            << "My title is: " << _title << '\n'
            << "My author is: "<< _author << endl;
    }

    const string& title() { return _title; }
    const string& author() { return _author; }


protected:
    string _title;
    string _author;
};

class AudioBook :public Book{
public:
    AudioBook( const string &title, const string &author, const string &narrator )
        : Book( title, author ), // 注释掉会报错
         _narrator( narrator )
    {
        cout << "AudioBook::AudioBook( " << _title 
        << ", " << _author 
        << ", " << _narrator 
        << " ) constructor\n" ;
    }

    ~AudioBook()
    {
        cout << "AudioBook::~AudioBook() destructor!\n";
    }

    virtual void print() const {
        cout << "AudioBook::print() -- I am an AudioBook object!\n";

        /**注意：以下直接访问继承而来的
         * data member: _title和_author**/
        cout<< "My title is: " << _title << '\n'
            << "My author is: " << _author << '\n'
            << "My narrator is: " << _narrator << endl;
    }

    const string& narrator() const { return _narrator; }
protected:
    string _narrator;
};

void print( const LibMat &mat );
/**definition of class num_sequence**************************************************************/



class new_num_sequence{
public:
    virtual ~new_num_sequence() {}
    /**virtual const char* what_am_i() const = 0:
     * 此类为纯虚函数，后面赋值为零，即在基类没有此函数的定义，在派生类中才进行定义
     * virtual int elem( int pos ) const：
     * 此类为虚函数，在基类就已经有定义，若强制置零，但是派生类没有此函数的定义会报错**/
    virtual const char* what_am_i() const = 0;//返回确切的数列类型
    virtual int elem( int pos ) const ;  // 返回pos位置上的元素
    virtual ostream& print( ostream &os = cout ) const ; //将所有元素写入os

    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
    static int max_elems() { return _max_elems; } //返回所支持的最大位置值

protected:
    virtual void gen_elems( int pos ) const = 0;  //产生直到pos位置的所有元素
    bool check_integrity( int pos, int size ) const; //检查pos是否为有效位置

    new_num_sequence( int len, int bp, vector<int> &re )
        : _length( len ), _beg_pos( bp ), _relems( re ){}

    const static int _max_elems = 1024;

    int _length;
    int _beg_pos;
    vector<int> &_relems;

};

class Triangulars : public new_num_sequence{
public:
    Triangulars( int len = 1, int beg_pos = 1);

    virtual const char* what_am_i() const { return "Triangular"; }


        
protected:
    virtual void gen_elems( int pos ) const;
    static vector<int> _elems;  
    /**！！！还要在头文件再次进行声明，
     * 不然报错chapter5.cpp:(.text+0xc4): undefined reference to `Triangulars::_elems'
     * **/
};

inline Triangulars::Triangulars( int len, int beg_pos )
    : new_num_sequence( len, beg_pos, _elems ) {}


class Pell : public new_num_sequence{
public:
    Pell( int len = 1, int beg_pos = 1);
    virtual const char* what_am_i() const { return "Pell"; }
        
protected:
    virtual void gen_elems( int pos ) const;
    static vector<int> _elems;  
    /**主要在头文件再次进行声明，
     * 不然报错chapter5.cpp:(.text+0xc4): undefined reference to `Triangulars::_elems'
     * **/
};

inline Pell::Pell( int len, int beg_pos )
    : new_num_sequence( len, beg_pos, _elems ) {}

class Lucas : public new_num_sequence{
public:
    Lucas( int len = 1, int beg_pos = 1);
    virtual const char* what_am_i() const { return "Lucas"; }

protected:
    virtual void gen_elems( int pos ) const;
    static vector<int> _elems;  
    /**主要在头文件再次进行声明，
     * 不然报错chapter5.cpp:(.text+0xc4): undefined reference to `Triangulars::_elems'
     * **/
};

inline Lucas::Lucas( int len, int beg_pos )
    : new_num_sequence( len, beg_pos, _elems ) {}


ostream& operator<<( ostream &os, const new_num_sequence &ns );
/**definition of class num_sequence**************************************************************/

class num_sequence{
public:
    typedef void (num_sequence::*PtrType)( int ); // 注意此处的定义

    enum ns_type{
        ns_unset, ns_pell, ns_triangular, ns_lucas
    };

    /** _pmf可以指向下列任意一个函数**/
    void pell( int );
    void triangular( int );
    void lucas( int );
    /*****************************/

    int elem( int pos);
    bool check_integrity( int pos ) ;
    void set_sequence( ns_type nst );
    const char* what_am_i() const;
    ns_type nstype( int num );  // 校验其整数参数是否代表某一个有效数列
    
    int num_of_sequence() const { return num_seq; }
    static int max_elems() { return _max_elems; }
    

private:
    PtrType _pmf; // 指向目前所用的算法（用以计算数列）
    vector<int>* _elem; // 指向目前的vector
    ns_type _isa; // 指向目前的数列类型

    static const int _max_elems = 1024; // a member with an in-class initializer must be const
    static const int num_seq = 4;
    static PtrType func_tbl[ num_seq ];
    static vector<vector<int> > seq;
   
};


/**Statement**************************************************************/

void display(  num_sequence &ns, int pos, ostream &os=cout);

#endif