#include <iostream>
#include <vector>

using namespace std;

double _sqrt_ (double val)
{
	if ( val < 0 )
		throw val;
	...
	
}

int main()
{
	try
	{
		double D = -1;
		double res = _sqrt_(D);
	}	
	catch ( double val )
	{
		cout << "Wrong value of D" << val << "\n";
	}
	
	return 0;
}
/*
	// Отлавливает многие исключения
	catch ( exception e )
	{
		cout << e.what();
	}
	
	// Отлавливает вообще все исключения
	catch ( ... )
	{
		
	}
*/

