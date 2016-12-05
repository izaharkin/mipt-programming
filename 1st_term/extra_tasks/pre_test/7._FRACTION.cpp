#include <iostream>

using namespace std;

int gcd (int a, int b)
{
	while ( b )
	{
		a %= b;
		swap(a, b);
	}
	
	return a;
}

int main()
{
	int n;
	
	cin >> n;
	
	int i = n >> 1, j = n >> 1;
	if ( n & 1 ) j++;
	else 
		while ( gcd(i, j) != 1 ) i--, j++;
	
	cout << i << " " << j;	
	
	return 0;
}
