#include <iostream>
#include <vector>

using namespace std;

int maximum (const vector <int>& arr, int left, int right)
{	
	if ( left == right )
		return arr[left];

	int m = (left + right) >> 1;
	int u = maximum(arr, left, m);
	int v = maximum(arr, m+1, right);
	
	return (u > v) ? u : v;
}

int fib (int n)
{
	if ( n < 0 ) throw n;
	if ( n < 2 ) return 1;
	return fib(n-1) + fib(n-2);
}

int main()
{
	
	
	return 0;
}
