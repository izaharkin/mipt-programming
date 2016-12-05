#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char *strlower (const char *s)
{
	int len = strlen(s);	
	char *t = (char *)malloc( sizeof(char)*len );

	for (int i = 0; i < len; ++i)
	{
		t[i] = s[i];
		if ( 'A' <= s[i] && s[i] <= 'Z' )
			t[i] -= 'A' - 'a';
	}
		
	return t;	
}

int main()
{
	const char *s = "ZAHARKINILYA";
	
	char *a = strlower(s);
	
	printf("%s", a);
	
	free(a);
	
	return 0;
}
