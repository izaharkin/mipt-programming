#include <iostream>
#include <cstring>
#include <cstdlib>
#include <malloc.h>

using namespace std;

char* convert(const char * str)
{
	int len = strlen(str);
	char *res;
	res = (char *)malloc(sizeof(char)*len);
	
	for (int i = 0; i < len; i++)
		res[i] = str[i];
	
	int cnt = 1;
	for (int i = 0; i < len; i++)
	{
		if ( 'a' <= res[i] && res[i] <= 'z' )
		{
			if ( cnt & 1 )
				res[i] = 'A' + (res[i]-'a');
			cnt++;
		}
		
		if ( 'A' <= res[i] && res[i] <= 'Z' ) 
		{
			if ( !(cnt & 1) )
				res[i] = 'a' + (res[i]-'A');
			cnt++;
		}
	}
	
	return res;
}

int mian()
{
	printf("%s\n", convert("Hello,world!"));
	
	return 0;
}
