#include "inc/stack.h"
#include "inc/con.h"
#include "inc/function.h"
#include "inc/demo.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <cctype>

ostream&
operator<<( ostream &os, const Triangular &rhs )
{
    os << "( "
	    << rhs.beg_pos() << " , "
	    << rhs.length()  << " ) ";

    rhs.display( rhs.length(), rhs.beg_pos(), os );
    return os;
}


using namespace std;



int main(void)
{

	

	int seq_size = 3;
	int pt;
	int ai[ 3 ] = {6, 7, 6};
	vector<int> pell_seq(ai, ai+seq_size);

	Triangular tri(20, 3);

	tri.gen_elements( tri.length() );

	cout << tri << endl;
	// tri.display(tri.length(), tri.beg_pos());

	//iterator_class_test_demo();

	//is_elem_test_demo();

	//stack_test_demo( pell_seq );
	
	//Triangular_test_demo();

	//Matrix_test_demo();

	return 0;
} 