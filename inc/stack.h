#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack{
public:
	bool push( const int& );
	bool pop( int &elem );
	bool peek( int &elem );

	bool empty();
	bool full();

	int size() { return _stack.size(); }

	void dispaly();

private:
	vector<int> _stack;

};

inline bool 
Stack::empty()
{
	return _stack.empty();
}



inline bool 
Stack::full()
{
	return _stack.size() == _stack.max_size();
}

inline bool
Stack::pop( int &elem )
{
	if( empty() )
		return false;

	elem = _stack.back();
	_stack.pop_back();
	return true;
}

inline bool 
Stack::peek( int &elem)
{
	if( full() )
		return false;

	elem = _stack.back();

	return true;

}

inline bool
Stack::push( const int &elem)
{
	if( full() )
		return false;

	_stack.push_back( elem );
	return true;
}

inline void
Stack::dispaly()
{
	for( int ix = 0; ix < _stack.size(); ix++ )
	{
		cout << _stack[ix] << " " ;
	}
	cout << endl;
}




#endif