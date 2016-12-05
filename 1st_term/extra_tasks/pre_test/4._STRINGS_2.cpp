#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string s[250];
	int n, cnt = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> s[i];
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = j+1; k < n; k++)
				if ( j != i && k != i )
					if ( s[j] + s[k] == s[i] || s[k] + s[j] == s[i] )
						cnt++;	
	
	cout << cnt;
	
	return 0;
}
