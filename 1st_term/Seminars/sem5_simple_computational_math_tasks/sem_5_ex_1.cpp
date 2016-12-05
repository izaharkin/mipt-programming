// Простейшие методы выч. математики (ГЛАВА 8)
#include <iostream>
//#include <std_lib_facilities>
#include <cmath>

using namespace std;

double func_a (double x)
{
	return pow(x, 5) - 1;
}

double func_b (double x)
{
	return sqrt(x)-tan(x);
}

double func_c (double x)
{
	return sqrt(x)-cos(x);
}

double root1 (double func(double), double a, double b, double eps, int& cnt)
{
	double l = a, r = b, x;
	
	if ( func(a) * func(b) > 0 ) return -10000000000;
	
	cnt = 0;
	while ( fabs(r-l) >= eps )
	{
		x = (l + r) * 0.5;
		if ( func(a) * func(x) <= 0 ) r = x;
		if ( func(b) * func(x) <= 0 ) l = x;
		cnt++;
	}
	
	return x;
}

double root2 (double f(double), double a, double b, double eps, int& cnt)
{
	double l = a, r = b;
	
	cnt = 0;
	while ( fabs(r - l) >= eps )
	{
		l = (l*f(r) - r*f(l))/(f(r) - f(l));
        r = (r*f(l) - l*f(r))/(f(r) - f(l));
        cnt++;
	}

	return r;
}

int main()
{
	double eps = 1e-10;
	double a, b, ans;
	int cnt = 0;
	
	cout.precision(10);
	
	a = 0; b = 2;
	ans = root1 (func_a, a, b, eps, cnt);
	cout << "Binary mothod: " << ans << " [" << cnt << " iterations]" << "\n";
	ans = root2 (func_a, a, b, eps, cnt);
	cout << "Chords mothod: " << ans << " [" << cnt << " iterations]" << "\n";
	
	a = 0.05; b = M_PI*0.5-0.05;
	ans = root1 (func_b, a, b, eps, cnt);
	cout << "Binary mothod: " << ans << " [" << cnt << " iterations]" << "\n";
	ans = root2 (func_b, a, b, eps, cnt);
	cout << "Chords mothod: " << ans << " [" << cnt << " iterations]" << "\n";
	
	a = 0; b = M_PI*0.5;
	ans = root1 (func_c, a, b, eps, cnt);
	cout << "Binary mothod: " << ans << " [" << cnt << " iterations]" << "\n";
	ans = root2 (func_c, a, b, eps, cnt);
	cout << "Chords mothod: " << ans << " [" << cnt << " iterations]" << "\n";
	
	return 0;
}
