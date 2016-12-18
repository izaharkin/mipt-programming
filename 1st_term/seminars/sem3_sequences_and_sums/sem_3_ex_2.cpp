#include <iostream>

using namespace std;

double half (double eps)
{
	double res = 1;
	
	for (int k = 2; eps < 1. / (k*k); k++)
		res *= 1. - 1. / (k*k);
	
	return res;
}

int main()
{
	cout << half(1e-18) << '\n';
	
	return 0;
}
