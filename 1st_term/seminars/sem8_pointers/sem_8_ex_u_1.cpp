#include <iostream>

using namespace std;

void to_lower (char* s)
{
	int i = 0;
	while ( s[i] != '\0' )
	{
		if ( 'A' <= s[i] && s[i] <= 'Z')
			s[i] = 'a' + (s[i] - 'A');
		i++;
	}
}

int main()
{
/*	char ch = '\0';
	char *pc = &ch;
	
	cout << pc;
*/		
	char *s = "Hello, World!";
	char c;
	int i = 0;
	
/*	cin >> c;
	while ( c != '\0' )
	{
		s[i++] = c;
		cin >> c;
	}*/
		
	to_lower(s);
	
//	cout << s;
	
	return 0;
}
