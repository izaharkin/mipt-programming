#include <iostream>
#include <cmath>

using namespace std;

double rev_pi ()
{
	double res = 1, cur = 0;
	
	for (int i = 0; i < 100; i++)
	{
		cur =  sqrt(0.5 * (1. + cur));
		res *= cur;
	}
	
	return res;
}

int main()
{
	cout << rev_pi() / 2. << '\n';
	
	return 0;
}
