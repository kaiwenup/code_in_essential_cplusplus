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

	char ch;
	bool more = true;
	
	Triangular tri(10, 1);

	tri.gen_elements( tri.length() );


	while( more )
	{
		cout << "Enter value: ";
		int ival;
		bool is_elem;
		cin >> ival;

		if( !isdigit( ival%10 ) )
		{
			is_elem = tri.is_elem( ival );
			//输入字符会有问题
			cout << ival;
			
			cout << ival << ( is_elem  ? " is " : " is not ")
					<< "an element in Triangular series. \n"
						<< "Another value?(Y/N):";

			cin >> ch;

			if( ch == 'n' || ch == 'N')
				more = false;
		
		
		}
		
	
	}

	


	//stack_test_demo( pell_seq );
	
	//Triangular_test_demo();

	//Matrix_test_demo();

	return 0;
} 