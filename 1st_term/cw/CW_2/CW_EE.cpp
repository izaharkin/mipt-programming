#include <iostream>
#include <malloc.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

char* convert(const char * str)
{
	int len = strlen(str);
	char *res;
	res = (char *)malloc(sizeof(char)*(len+1));
	
	for (int i = 0; i < len; i++)
		res[i] = str[i];
	
	int cnt = 1;
	for (int i = 0; i < len; i++)
	{
		if ( 'a' <= str[i] && str[i] <= 'z' )
		{
			if ( cnt & 1 )
				res[i] = 'A' + (res[i]-'a');
			cnt++;
		}
		
		if ( 'A' <= str[i] && str[i] <= 'Z' ) 
		{
			if ( !(cnt & 1) )
				res[i] = 'a' + (res[i]-'A');
			cnt++;
		}
	}
	
	res[len] = '\0';
	
	return res;
}

 int main()
 {
 	printf("%s\n", convert("Hello,world!"));
 	
 	return 0;
 }
