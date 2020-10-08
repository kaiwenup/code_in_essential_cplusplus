#include "demo.h"

/**
 * is_elem test demo 
 * no ok 
 * Bug: 输入字符的时候有问题
**/
void is_elem_test_demo()
{
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


		is_elem = tri.is_elem( ival );
		//输入字符会有问题

		cout << ival << ( is_elem  ? " is " : " is not ")
				<< "an element in Triangular series. \n"
					<< "Another value?(Y/N):";

		cin >> ch;

			if( ch == 'n' || ch == 'N')
				more = false;
		

		
	
	}
}

/**
 * stack test demo
 * ok
**/
void stack_test_demo(vector<int> &ve )
{
    Stack dog;
    for(int ix =0; ix < ve.size(); ix++)
	{
		dog.push( ve[ ix ] );
	}

	dog.dispaly();
}
/**
 * triangular test demo
 * ok
**/
void Triangular_test_demo()
{
    Triangular tri(3, 1);
	Triangular tri1, tri2;

	tri.display();
	
	tri.push(6);
	tri.push(2);
	tri.push(5);
	cout << "-0- sum of elements: "
		<< sum( tri ) << endl;

	tri1.copy( tri );

	tri1.push(10);
	tri1.push(1);
	tri1.push(12);
	
	tri1.display();

    //因为定义了 static vector<int> _elems，所以两个类的调用sum函数，结果都是一样的。
	cout << "-1- sum of elements: "
		<< sum( tri1 ) << endl;
}
/** 
 * class Matrix test demo 
 * ok
**/
void Matrix_test_demo()
{
    Matrix mat(4 , 4);
	mat.display();
}