#include "demo.h"

/**chapter5 test demo**/
/**5.1 漫游：面向对象编程思维**/ 
void three_tier_class_test_demo()
{
	// cout << "\n" << "Creating a LibMat object to print()\n";

	// LibMat libmat;

	// print( libmat );

	// cout << "Creating a Book object to print() \n";
	// Book b( "The Catle", "Franz Kafka");
	// print( b );

	AudioBook ab("Mason and Dixon", "Thomas Pynchon", "Edwin Leonard");

	cout << "The title is: " << ab.title() << '\n'
		<< "The author is: " << ab.author() << '\n'
		<< "The narrator is: " << ab.narrator() << endl;
}

/***5.2~5.3*/
void num_sequence_test_demo()
{
	num_sequence ns;
	const int pos = 8;

	for( int ix = 1; ix < ns.num_of_sequence(); ++ix )
	{
		ns.set_sequence( ns.nstype( ix ));
		// int elem_val = ns.elem( pos );
		display(ns, pos);
	}
}
/**5.7~~5.8**/
void new_sequence_test_demo()
{
	Triangulars tri;
	cout << tri << endl;
	
	Pell tri2(16);
	cout << tri2 << endl;
	
	Lucas tri3(8, 12);
	cout << tri3 << endl;
}


/**chapter4 test demo**/
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

	//tri.gen_elements( tri.length() );

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

	// tri.display();
	
	tri.push(6);
	tri.push(2);
	tri.push(5);
	cout << "-0- sum of elements: "
		<< sum( tri ) << endl;

	tri1.copy( tri );

	tri1.push(10);
	tri1.push(1);
	tri1.push(12);
	
	// tri1.display();

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

void iterator_class_test_demo()
{
	Triangular tri( 30 );
	tri.gen_elements( tri.length() );
	/**
	 * Triangular::iterator怎么来的？
	 * 1. typedef Triangular_iterator Triangular::iterator
	 * 此时Triangular::iterator与Triangular_iterator等价
	 * 2. tri.begin()这一步调用Triangular_iterator begin() const
	 * 此时函数返回Triangular_iterator( _beg_pos )，这一步调用
	 * inline int Triangular_iterator::operator*() const
	 * 返回索引值对应的数值
	 **/
	Triangular::iterator it = tri.begin();
	Triangular::iterator end_it = tri.end();

	cout << "Triangular Series of " << tri.length() << " elements\n";
	// cout << tri << endl;

	/**
	 * it != end_it c++没有直接支持该语句的语法，需要自己定义iterator_class
	 * 定义语句为：
	 * inline bool Triangular_iterator::
    	operator!= ( const Triangular_iterator &rhs) const
                { return !( *this == rhs ); }
	**/
	while( it != end_it ){
		cout << *it << ' ';
		++it;
	}

	cout << endl;
}

int function_object_test_demo( const vector<int> &vec, int comp )
{
	LessThan lt( comp );

	int count = 0;

	for( int ix = 0 ; ix < vec.size(); ix++)
	{
		if( lt( vec[ ix ]) )
		{
			++count;
		}
	}

	return count;
}

/**默认值的设定应该放在声明处（头文件），而不是定义处**/
void print_less_than( const vector<int> &vec, int comp, ostream &os )
{
	LessThan lt( comp );
	vector<int>::const_iterator iter = vec.begin();
	vector<int>::const_iterator end_iter = vec.end();

	os << "elements less than " << lt.com_val() << endl;

	while(( iter = find_if(iter, end_iter, lt)) != end_iter )
	{
		os << *iter << endl;
		iter++;
	}
}

void overload_iostream_test_demo()
{
	Triangular tri(20, 3);

	tri.gen_elements( tri.length() );

	cout << tri;
}

