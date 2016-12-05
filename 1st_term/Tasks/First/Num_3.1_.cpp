#include <iostream>

using namespace std;

int main()
{
	int n, x, Max;
	
	cin >> n;
	
	cin >> Max;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		(x > Max) && x == (Max = x);
		/*
		if ( x > Max )
			Max = x;
		*/
	}
	
	cout << Max;
	
	return 0;
};
