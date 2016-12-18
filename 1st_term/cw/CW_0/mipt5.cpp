#include <iostream>

using namespace std;

int main()
{
	int s = 0, n, a[105] = {0};
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	
	int k = s / n;
	
	for (int i = 0; i < n; i++)
		cout << k - a[i] << " ";
	
	return 0;
}
