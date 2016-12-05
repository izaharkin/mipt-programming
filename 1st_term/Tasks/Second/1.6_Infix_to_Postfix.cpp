#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

bool isop (char c)
{
  	if ( c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '(' )
    	return true;
  	return false;
}

int main()
{
  	char c = '0';
  	stack <char> ops;
	string out = "";
	string s;
	
	cin >> s;
  	for (int i = 0; i < s.length(); ++i)
    {
      	bool op = isop(s[i]);
      	
      	if ( op )
	  		ops.push(s[i]);
      	else if ( s[i] != ')' ) // if number
		{
			while ( isalnum (s[i]) ) out += s[i++];
			--i; 
			out += " "; 
		}
      	else if ( s[i] == ')' )
		{
	  		while ( ops.top() != '(' )
	    	{
	     		out += ops.top(); 
				out += " ";
	      		ops.pop();
	    	}
	  		ops.pop();  // pop '('
		}
    }
  	
	while ( ops.size() != 0 )
    {
		out += ops.top(); 
		out += " ";
      	ops.pop();
    }
    
  	cout << out << endl;
  
  	return 0;
}
