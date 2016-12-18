#include <iostream>
#include <cmath>

using namespace std;

double func (double x)
{
	return tan(x) - x;
}

double root (double func(double), double a, double b, double eps)
{
	double x, l = a, r = b;
	
	if ( func(a) * func(b) > 0)
		return 101010;
	
	while ( abs(r - l) >= eps )
	{
		x = (l + r) / 2;
		if ( func(a) * func(x) <= 0 ) r = x;
		if ( func(b) * func(x) <= 0 ) l = x;
	}
	
	return x;
}

int main()
{
	double a, b, eps = 1e-10;
	
	cin >> a >> b;
	
	cout.precision(10);
	cout << root(func, a, b, eps);
	
	return 0;
}
