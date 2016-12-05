#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
  	stack<char> line;
  	string s;
  	
  	cin >> s;
  	int len = s.length();
  	for (int i = 0; i < len; i++)
    {
      	char &c = s[i];
      	
      	if ( c == '{' || c == '(' )
			line.push(c);      
      	else if ( (line.top() == '{' && c == '}') || (line.top() == '(' && c == ')') )
	  		line.pop();
		else if ( c != ')' && c != '}' )
	  	{
	    	cout << "Not correct word" << endl;
	    	return -1;
	  	}
    }
  	
	if ( line.size() == 0 )
		cout << "Correct" << endl;
  	else 
	  	cout << "Not correct" << endl;
	  	
  	return 0;
}
