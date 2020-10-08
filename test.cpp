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

using namespace std;

int main(void)
{

	

	int seq_size = 3;
	int pt;
	int ai[ 3 ] = {6, 7, 6};
	vector<int> pell_seq(ai, ai+seq_size);


	is_elem_test_demo();

	//stack_test_demo( pell_seq );
	
	//Triangular_test_demo();

	//Matrix_test_demo();

	return 0;
} 