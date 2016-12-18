// Простейшие методы выч. математики (ГЛАВА 8)
#include <iostream>
//#include <std_lib_facilities>
#include <cmath>

using namespace std;

double func_a1 (double x)
{
	return cos(x);
}

double func_a2 (double x)
{
	return sin(x);
}

double func_a3 (double x)
{
	return pow(x, 3);
}

double func_b (double x)
{
	return sqrt(1 - 0.25*sin(x)*sin(x));
}

double func_c (double x)
{
	return 1. / func_b(x);
}

double integrate (double f(double), double a, double b)
{
	double sum = 0, xi, h = 0.5*(b - a);

	for (xi = a + h; xi < b; xi += h)
		sum += f(xi);
	sum = (sum + 0.5*(f(a) + f(b))) * h;
	
	return sum;
}

int main()
{
	double eps = 1e-10;
	double a, b, ans;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	
	cout.precision(10);
	
	a = 0; b = 2*M_PI;
	ans = integrate (func_a1, a, b);
	cout << ans << "\n";
	
	a = 0; b = 2*M_PI;
	ans = integrate (func_a2, a, b);
	cout << ans << "\n";
	
	a = 0; b = 1;
	ans = integrate (func_a3, a, b);
	cout << ans << "\n";
	
	a = 0; b = M_PI*0.5;
	ans = integrate (func_b, a, b);
	cout << ans << "\n";
	
	a = 0; b = M_PI*0.5;
	ans = integrate (func_c, a, b);
	cout << ans << "\n";
	
	return 0;
}
