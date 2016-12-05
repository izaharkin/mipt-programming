#include <iostream>
#include <vector>

using namespace std;

class Fibonacci
{
private:
	vector <int> cache;
	int fib (int n)
	{
		if ( cache[n] == 0 )
			cache[n] = fib(n-1) + fib(n-2);
		return cache[n];
	}
public:
	Fibonacci () : cache(2)
	{
		cache[0] = cache[1] = 1;
	}
	int compute (int n)
	{
		if ( n < 0 ) throw n;
		if ( cache.size() < size_t(n) )
			cache.resize(n+1, 0);
		return fib(n);
	}
};

int main()
{
	Fibonacci f;

	cout << f.compute(6);
	
	return 0;
}
