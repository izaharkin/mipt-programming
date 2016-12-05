#include <iostream>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	bool flag = false;
	while ( n != 1 )
	{
		if ( n & 1 ) flag = true;
		n >>= 1;
	}
	
	cout << (flag ? "NO" : "YES");
	
	return 0;
}
