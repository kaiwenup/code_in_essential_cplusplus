#ifndef _CHAPTER5_H_
#define _CHAPTER5_H_
#include "con.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

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

/************************************************************************/

class num_sequence{
public:
    typedef void (num_sequence::*PtrType)( int );

    /** _pmf可以指向下列任意一个函数**/
    void pell( int );
    void lucas( int );
    void triangular( int );

    

    enum ns_type{
        ns_unset, ns_pell, ns_lucas, ns_triangular
    };

    static ns_type nstype( int num )
    {
        return num <= 0 || num >= num_seq
            ? ns_unset // 无效值
            : static_cast< ns_type >( num );
    }

    void set_sequence( ns_type nst );
    const char* what_am_i() const;
    int elem( int pos);
private:
    PtrType _pmf; // 指向目前所用的算法（用以计算数列）
    vector<int>* _elem; // 指向目前的vector
    static const int num_seq = 4;
    static PtrType func_tbl[ num_seq ];
    static vector<vector<int> > seq;
    ns_type _isa;
};

inline void display( const num_sequence &ns, int pos, ostream &os=cout)
{
    os << "The elements at position "
        << pos << " for the "
        << ns.what_am_i() << "sequence is "
       // << ns.elem( pos ) 
        << endl;
}


#endif