#include <iostream>

using namespace std;

int main()
{
	int x, Max;
	
	cin >> Max;

	while ( cin >> x )
		x > Max && x == (Max = x);
	
	cout << Max;
	
	return 0;
}
