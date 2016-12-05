#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// Detect repeated words
int main()
{
	string previous = " ";
	string current;
	
	while ( cin >> current )
	{
		if ( previous == current )
			cout << "Repeated word: " << current << '\n';
		previous = current;
	}
	
	return 0;
}
