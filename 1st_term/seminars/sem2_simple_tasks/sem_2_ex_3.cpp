#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	double a, b;
	string operation = "";
	
	while ( cin >> operation )
	{
		cin >> a >> b;
		if ( operation == "+" || operation == "plus" )
			cout << " " << a + b << '\n';
		else if ( operation == "-" || operation == "minus" )
			cout << " " << a - b << '\n';	
		else if ( operation == "*" || operation == "mul" )
			cout << " " << a * b << '\n';
		else if ( operation == "/" || operation == "div" )
			cout << " " << a / b << '\n';
	}
	
	return 0;
}
