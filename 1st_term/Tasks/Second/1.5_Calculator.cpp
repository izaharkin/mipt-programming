#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

bool space (const char& c)
{
	return c == ' ';
}

bool is_op (const char& c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int prior (const char& c)
{
	return (c == '-' || c == '+') ? 1 :
		   (c == '*' || c == '/' || c == '%') ? 2 : -1;	
}

void proc (stack <int>& st, char c)
{
	int r = st.top(); st.pop();
	int l = st.top(); st.pop();
	
	switch ( c )
	{
		case '+': st.push(l + r); break;
		case '-': st.push(l - r); break;
		case '*': st.push(l * r); break;
		case '/': st.push(l / r); break;
		case '%': st.push(l % r); break;
	}
}

int calc (const string& s)
{
	stack <int> num;
	stack <char> op;
	
	for (int i = 0; i < (int) s.length(); i++)
	{
		if ( !space(s[i]) )
		{
			if ( s[i] == '(' ) op.push(s[i]);
			else
			if ( s[i] == ')' )
			{
				while ( op.top() != '(' ) proc(num, op.top()), op.pop();
				op.pop();
			}
			else
			if ( is_op(s[i]) )
			{
				while ( !op.empty() && prior(op.top()) >= prior(s[i]) ) 
					proc(num, op.top()), op.pop();
				op.push(s[i]);	
			}
			else
			{
				string operand;
				
				while ( i < s.length() && isalnum (s[i]) ) operand += s[i++];
				--i;
				
				if ( isdigit (operand[0]) ) num.push(atoi(operand.c_str()));
				//else                      num.push ( get_variable_val (operand) );
			}
		}
	}
	
	while ( !op.empty() ) proc(num, op.top()), op.pop();
	
	return num.top();
}

int main()
{
	string s;
	
	cin >> s;
	
	cout << calc(s);
	
	return 0;
}
