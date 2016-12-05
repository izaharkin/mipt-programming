#include <iostream>

using namespace std;

int main()
{
	int n, C[101][101];
	
	cin >> n;
	
	for (int i = 0; i <= n; i++) 
	{
		C[i][0] = C[i][i] = 1;
		for (int k = 1; k < i; k++)
			C[i][k] = C[i-1][k-1] + C[i-1][k];
	}
	
	for (int i = 0; i <= n; i++)
			cout << C[n][i] << " ";
	
	return 0;
};
