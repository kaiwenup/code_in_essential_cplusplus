#include "chapter5.h"

/**definition of non-member function print()**/
void print( const LibMat &mat )
{
    cout << "in global print(): about to print mat.print()\n";

    mat.print();

}



/**definition of class new_num_sequence***************************************/
vector<int> Triangulars::_elems;
vector<int> Pell::_elems;
vector<int> Lucas::_elems;

bool new_num_sequence::check_integrity( int pos, int size ) const
{
    if( pos < 0 || pos > _max_elems)
    {
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";

        return false;
    }

    if( pos > size )
        gen_elems( pos );  

    return true;
}

int new_num_sequence::elem( int pos ) const 
{
    if( ! check_integrity( pos, this->_relems.size() ))
        return 0;
    
    if( pos > this->_relems.size() )
        gen_elems( pos );

    return this->_relems[ pos-1 ];
}


ostream& new_num_sequence::print( ostream &os) const 
{

    int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

    if ( ! check_integrity( end_pos, this->_relems.size() )) 
    /**注意这里的操作, 因为_relems是取值，所以无需指针操作**/
			 return os;

    os << this->what_am_i() << " beginning at element " << _beg_pos
        << " for " << _length << " elements: ";

	while ( elem_pos < end_pos )
		     os << this->_relems[ elem_pos++ ] << ' ';

	return os;
}

ostream& operator<<( ostream &os, const new_num_sequence &ns )
        { return ns.print( os ); }


void Triangulars::gen_elems( int pos ) const
{
 
    if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.size() <= pos )
	{
		int end_pos = pos+1;
		int ix = _elems.size() + 1;
        
		for ( ; ix <= end_pos; ++ix )
		    _elems.push_back( ix*(ix+1)/2 );
	}
}

void Pell::gen_elems( int pos ) const
{
    if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.empty() )
       {  _elems.push_back( 1 ); _elems.push_back( 2 ); }

    if ( _elems.size() <= pos )
	{
		    int ix = _elems.size();
			int n_2 = _elems[ ix-2 ], 
				n_1 = _elems[ ix-1 ];

			int elem;
			for ( ; ix <= pos; ++ix ){
				    elem = n_2 + 2 * n_1; 
					_elems.push_back( elem );
					n_2 = n_1; n_1 = elem;
			}
	 }
}

void Lucas::gen_elems( int pos ) const 
{
    if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.empty() )
       {  _elems.push_back( 1 ); _elems.push_back( 3 ); }

    if ( _elems.size() <= pos )
	{
		    int ix = _elems.size();
			int n_2 = _elems[ ix-2 ], 
				n_1 = _elems[ ix-1 ];

			int elem;
			for ( ; ix <= pos; ++ix ){
				    elem = n_2 +  n_1; 
					_elems.push_back( elem );
					n_2 = n_1; n_1 = elem;
			}
	 }
}

/**definition of class num_sequence*******************************************/
const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq( num_seq );

num_sequence::PtrType num_sequence::func_tbl[ num_seq ] = 
{
    0,
    &num_sequence::pell,
    &num_sequence::triangular,
    &num_sequence::lucas
};

num_sequence::ns_type num_sequence::nstype( int num )  // 校验其整数参数是否代表某一个有效数列
    {
        /**注意手法**/
        return num <= 0 || num >= num_seq  
            ? ns_unset // 无效值
            : static_cast< ns_type >( num );
    }

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
        /**注意此处写法
         * 错误写法：
         * case ns_pell ns_triangular: ns_lucas:
        **/
        case ns_pell:      
        case ns_triangular: 
        case ns_lucas:
            _pmf = func_tbl[ nst ];  // 确定使用的函数
            _elem = &seq[ nst ];  // 确定数列
            _isa = nst;  // 确定数列名
            break;


    }
}

bool num_sequence::
check_integrity( int pos ) 
{
	bool status = true;

	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos
			  << " Cannot honor request\n";
		 status = false;
	}
    else if ( pos > (*_elem).size() )
		    (this->*_pmf)( pos );
            /**错误写法：(*_pmf)( pos ); 
             * 注意与(*_elem)区别**/

	return status;
}

int num_sequence::elem( int pos )
{
    if( ! check_integrity( pos ))
        return 0;

    return (*_elem)[ pos-1 ];
}

const char* num_sequence::what_am_i() const
{
    static char *names[ num_seq ] = { 
        (char*)"notSet", (char*)"pell", (char*)"triangular", (char*)"lucas"  
    };

    return names[ _isa ];
}


void num_sequence::pell( int pos )
{
    if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( (*_elem).empty() )
       {  (*_elem).push_back( 1 ); (*_elem).push_back( 2 ); }

    if ( (*_elem).size() <= pos )
	{
		    int ix = (*_elem).size();
			int n_2 = (*_elem)[ ix-2 ], 
				n_1 = (*_elem)[ ix-1 ];

			int elem;
			for ( ; ix <= pos; ++ix ){
				    elem = n_2 + 2 * n_1; 
					(*_elem).push_back( elem );
					n_2 = n_1; n_1 = elem;
			}
	 }
}
void num_sequence::lucas( int pos )
{
    if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( (*_elem).empty() )
       {  (*_elem).push_back( 1 ); (*_elem).push_back( 3 ); }

    if ( (*_elem).size() <= pos )
	{
		    int ix = (*_elem).size();
			int n_2 = (*_elem)[ ix-2 ], 
				n_1 = (*_elem)[ ix-1 ];

			int elem;
			for ( ; ix <= pos; ++ix ){
				    elem = n_2 +  n_1; 
					(*_elem).push_back( elem );
					n_2 = n_1; n_1 = elem;
			}
	 }
}
void num_sequence::triangular( int pos )
{
    if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( (*_elem).size() <= pos )
	{
		int end_pos = pos+1;
		int ix = (*_elem).size()+1;
		for ( ; ix <= end_pos; ++ix )
			  (*_elem).push_back( ix*(ix+1)/2 );
	}
}


void display(  num_sequence &ns, int pos, ostream &os)
{
    os << "The elements at position "
        << pos << " for the "
        << ns.what_am_i() << " sequence is "
        << ns.elem( pos ) 
        << endl;
}
