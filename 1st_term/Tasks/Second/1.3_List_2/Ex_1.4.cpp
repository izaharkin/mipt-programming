#include "list.h"
#include <cstring>
#include <string>

using namespace std;

int main()
{
	List <char> a;
	string s;
	
	cin >> s;
	
	for (int i = 0; i < s.length(); ++i)
	{
		if ( s[i] == '(' || s[i] == '{' )
			a.push_back();
		else
		{
			char t = a.last();
			if ( type(s[i], t) )
				a.pop_back();
			else
			{
				cout << "Wrong!";
				return 0;
			}
		}
	}
	
	cout << "OK";
	
	return 0;
}
