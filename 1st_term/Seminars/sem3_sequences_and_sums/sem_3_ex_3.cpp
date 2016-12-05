#include <iostream>

using namespace std;

int factorial (int n)
{
	int f = 1;
	
	for (; n > 1; n--)
		f *= n;
		
	return f;
}

double one (double eps)
{
	double res = 0;
	
	for (int k = 1; eps < double(k) / factorial(k+1); k++)
		res += double(k) / factorial(k+1);
	
	return res;
}

int main()
{
	cout << one(1e-12) << '\n';
	
	return 0;
}
