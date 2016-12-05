#include <iostream>
#include <cmath>

using namespace std;

double Cos (double x)
{
	return cos(x);
}

double integrate (double f(double), double a, double b)
{
	double s = 0, h = 0.5*(b - a);
	
	for (int i = a + h; i < b; i += h)
		s += f(i);
	s = (s + 0.5*(f(a) + f(b))) * h;
	
	return s;
}

int main()
{
	double a, b;
	
	cin >> a >> b;
	
	cout << integrate(Cos, a, b);
	
	return 0;
}
