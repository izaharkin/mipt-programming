#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <set>

using namespace std;

void strip (string &s)
{
/*	set <char> wd;
	
	wd.push(char(3));  // end of text
	wd.push(char(9));  // space
	wd.push(char(13)); // horizontal tab
	wd.push(char(32)); // carriage return
*/	
	char c = s[0];
	while ( s.length() > 0 && (c == char(3) || c == char(9) || c == char(13) || c == char(32) ) )
	{
		s.erase(0, 1);
		c = s[0];
	}
	
	if ( s.length() > 0 )
		c = s[s.length()-1];
	while ( s.length() > 0 && (c == char(3) || c == char(9) || c == char(13) || c == char(32) ) )
	{
		s.erase(s.length()-1, 1);
		c = s[s.length()-1];
	}
}

int main()
{
	string s;
	
	getline(cin, s);
	
	strip(s);
	
	cout << s;
	
	return 0;
}
