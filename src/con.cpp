#include "con.h"

vector<int> Triangular::_elems;

/**老版本 Triangular::display() **/
// void
// Triangular::display(){
//     cout << "length:" << _length
//         << " beg_pos:" << _beg_pos << endl;
// }

/**新版本 Triangular::display()**/
void Triangular::display( int length, int beg_pos, ostream &os )
{
	if ( length <= 0 || beg_pos <= 0 ){
		 cerr << "invalid parameters -- unable to fulfill request: "
			  << length << ", " << beg_pos << endl;
		 return;
	}

	int elems = beg_pos + length - 1;

	if ( _elems.size() < elems )
		 gen_elements( elems );

	for ( int ix = beg_pos-1; ix < elems; ++ix )
		  os << _elems[ ix ] << ' ';
    
    cout << endl;
}


Triangular& 
Triangular::copy( const Triangular &rhs ){
        if( this != &rhs )
        {
            _length = rhs._length;
            _beg_pos= rhs._beg_pos;
            _next = rhs._beg_pos - 1;
        }

        return *this;   
    }


bool
Triangular::is_elem( int value )
{
    if( !_elems.size() || _elems[ _elems.size() - 1] < value )
        gen_elems_to_value(value);

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it  = find( _elems.begin(), end_it, value);

    return found_it != end_it;
}

void 
Triangular::gen_elems_to_value( int value)
{
    int ix = _elems.size();
    if( !ix ){
        _elems.push_back( 1 );
        ix = 1;
    }

    while( _elems[ ix - 1] < value && ix < _max_elems )
    {
        ++ix;
        _elems.push_back( ix*(ix+1)/2 );
        if( DEBUG_CON )
            cout << "elems to value: " << ix*(ix+1)/2 << endl;
    }

    if( ix == _max_elems)
        cerr << "Triangular Sequence: oops: value too large"
            << value << " -- exceeds max size of "<< _max_elems << endl;
    // cerr不经过缓冲而直接输出，一般用于迅速输出出错信息
}


void Triangular::gen_elements( int length )
{
    if( length < 0 || length > _max_elems )
        cerr << "a error in generate elements";
    
    if( _elems.size() < length )
    {
        int ix = _elems.size() ? _elems.size()+1 : 1;

        for( ; ix <= length; ix++ )
        {
            _elems.push_back( ix*( ix+1 )/2 );
        }
    }

}

/**注意的头文件进行声明，不然主程序调用的时候会报错**/
ostream& operator<<( ostream &os, const Triangular &rhs )
{
    os << "( " << rhs.beg_pos() << ", " << rhs.length() << " ) ";

    rhs.display( rhs.length(), rhs.beg_pos(), os);

    return os;
}


