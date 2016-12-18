#include <iostream>

using namespace std;

int main()
{
	int s1 = 0, s2 = 0, n, k = 1, x;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		
		if ( k > 0 ) s1 += x;
		else         s2 += x;
		
		k *= -1;
	}
	
	if ( (s1 >= 13) || (s2 >= 13 ) )
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}
