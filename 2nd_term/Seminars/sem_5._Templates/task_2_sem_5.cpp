#include <iostream>

using namespace std;

template <int N>
class Factorial
{
public:
	static const int x = N * Factorial<N-1>::x;
};

template <>
class Factorial <0>
{
public:
	static const int x = 1;
};

int main ()
{
	cout << Factorial <5>::x;
	
	return 0;
}
