#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int Detect (string s) // Определяем систему счисления (с поддержкой регистра)
{
	int base = -1; // Начальное основание -1
	int len = s.length();
	
	for (int i = 0; i < len; i++) 
	{
		if ( s[i] >= '0' && s[i] <= '9' )
		{
			int temp = int(s[i] - '0') + 1;
			if ( temp > base ) base = temp; 
		}
		
		if ( s[i] >= 'a' && s[i] <= 'z' )
		{
			int temp = int(s[i]) - 86;
			if ( temp > base ) base = temp;
		}
		
		if ( s[i] >= 'A' && s[i] <= 'Z' )
		{
			int temp = int(s[i]) - 54;
			if ( temp > base ) base = temp;
		}
	}
	
	return base;
}

int main()
{
	int n;
	string s;
	
	cin >> s;
	
	cout << Detect(s);
	
	return 0;
}
