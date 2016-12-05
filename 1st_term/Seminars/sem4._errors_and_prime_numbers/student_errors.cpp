// This is a typical code which many students usually write.
// Try to find out what this code does and fix errors.

#include "std_lib_facilities.h"

int main()
{	
	int n, k, order = 0;
	
	cin >> order;
	
	n = order;
	k = 0;
	for (int i = 0; i <= n; i++)
	{
		int n1 = 1;
		for(int j = n; j > 1; j--)
			n1 *= j;
			
		int k1 = 1;
		for(int j = k; j > 1; j--)
			k1 *= j;
			
		int nk1 = 1;
		for(int j = n-k; j > 1; j--)
			nk1 *= j;
			
		cout << n1 / (k1 * nk1) << " ";
		k++;     
	}
	cout << "\n";
}
