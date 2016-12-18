#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string s;
	
	while ( cin >> s )
	{
		if ( s == "one" )
			cout << 1;
		else if ( s == "two" )
			cout << 2;
		else if ( s == "three" )
			cout << 3;
		else if ( s == "four" )
			cout << 4;
		else
			cout << "Number I don`t know";
	}
	
	return 0;
}
