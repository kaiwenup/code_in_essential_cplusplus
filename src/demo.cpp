#include "demo.h"

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