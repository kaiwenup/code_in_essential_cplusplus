#include "function.h"

int sum( const Triangular &train )
{
    if( ! train.length() )
	{
		cout << "error" << endl;
		return false;
	}
        

    int val, sum=0;

    train.next_reset();
    while( train.next( val ))
        sum += val;

    return sum;

}
