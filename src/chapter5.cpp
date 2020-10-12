#include "chapter5.h"




/**definition of non-member function print()**/
void print( const LibMat &mat )
{
    cout << "in global print(): about to print mat.print()\n";

    mat.print();

}

const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq( num_seq );

num_sequence::PtrType num_sequence::func_tbl[ num_seq ] = 
{
    0,
    &num_sequence::pell,
    &num_sequence::lucas,
    &num_sequence::triangular
};

void num_sequence::set_sequence( ns_type nst )
{
    switch ( nst )
    {
        default:
            cerr << "ivalid type: setting to 0\n";
            // 刻意执行下去，不做break操作
        case ns_unset:
            _pmf = 0;
            _elem = 0;
            _isa = ns_unset;
            break;
        case ns_pell: ns_lucas: ns_triangular:
            _pmf = func_tbl[ nst ];
            _elem = &seq[ nst ];
            _isa = nst;
            break;


    }
}

const char* num_sequence::what_am_i() const
{
    static char *names[ num_seq ] = {
        "notSet", "pell", "lucas", "triangular"
    };

    return names[ _isa ];
}
// not ok
// int num_sequence::elem( int pos )
// {
//     return (*num_sequence::seq)[pos-1];
// }

void num_sequence::pell( int val )
{

}
void num_sequence::lucas( int val )
{
    
}
void num_sequence::triangular( int val )
{
    
}

