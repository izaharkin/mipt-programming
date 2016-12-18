#include <iostream>

using namespace std;

int main()
{
	int n, m, k;
	
	cin >> n >> m >> k;
	
	int a = m * k;
	int y = a / n;
	
	if ( y > k ) cout << "NO";
	else         cout << "YES";
	
	return 0;
}
