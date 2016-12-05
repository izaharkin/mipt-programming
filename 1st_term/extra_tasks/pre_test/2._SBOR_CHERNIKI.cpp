#include <iostream>

using namespace std;

int main()
{
	int a[1005], s[1005], n, t, Max = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	a[n] = a[0];
	a[n+1] = a[1];
	
	for (int i = 0; i < n; i++)
	{
		t = a[i] + a[i+1] + a[i+2];
		if ( t > Max ) 
			Max = t;
	}
	
	cout << Max;
	
	return 0;
}
