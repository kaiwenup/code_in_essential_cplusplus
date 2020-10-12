#include "inc/stack.h"
#include "inc/con.h"
#include "inc/function.h"
#include "inc/demo.h"
#include "inc/chapter5.h"

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


using namespace std;



int main(void)
{	
	int seq_size = 3;
	int pt = 8;
	int ai[ 3 ] = {6, 7, 6};
	vector<int> pell_seq(ai, ai+seq_size);


	Triangular tri(20, 3);

	tri.gen_elements( tri.length() );

	/**  Chapter 5 test demo **/

	three_tier_class_test_demo();


	/**  Chapter 4 test demo **/
	
	// overload_iostream_test_demo();

	// print_less_than( pell_seq, pt);
	
	// tri.display(tri.length(), tri.beg_pos());

	// iterator_class_test_demo();

	// is_elem_test_demo();

	//stack_test_demo( pell_seq );
	
	//Triangular_test_demo();

	//Matrix_test_demo();

	return 0;
} 