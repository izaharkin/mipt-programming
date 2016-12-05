#include <iostream>

using namespace std;

int main()
{
	int n, f1, f2, f3;
	
	cin >> n;
	
	f1 = f2 = 1;
	for (int i = 2; i < n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	
	cout << f3;
	
	return 0;
};
