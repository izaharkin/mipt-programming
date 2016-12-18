#include <iostream>
#include <vector>

using namespace std;

class Fibonacci
{
public:
	static vector <int> cache;
private:	
	static int fib (int n)
	{
		if ( cache[n] == 0 )
			switch (n)
			{
				case 0: case 1: cache[n] = 1; break;
				default: cache[n] = fib(n-1) + fib(n-2);
			}
		return cache[n];
	}
	Fibonacci () {}
public:
	static int compute (int n)
	{
		if ( n < 0 ) throw n;
		if ( cache.size() < size_t(n) )
			cache.resize(n+1, 0);
		return fib(n);
	}
};

vector <int> Fibonacci:: cache; 

int main()
{
	int ans = Fibonacci::compute(5);
	
	cout << ans;
	
	return 0;
}
