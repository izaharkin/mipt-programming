#include <iostream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

int n, cnt = 0;
string res;
stack <char> s;

void input ()
{
	cin >> n;
	res.resize(2*n);
}

// pos - текущая позиция, на которую нужно поставить скобку
// op_br_cnt - количество открытых скобок на данный момент
void true_br_seq (int pos, int op_br_cnt)
{
	if ( pos == 2*n )
	{
		cnt++;
		cout << res << "\n";
		return;
	}
	
	if ( op_br_cnt < 2*n-1-pos )
	{
		res[pos] = '(';
		s.push('(');
		
		true_br_seq(pos+1, op_br_cnt+1);
		
		s.pop();
		res[pos] = ' ';
	}
	
	if ( !s.empty() )
	{
		res[pos] = ')';
		s.pop();
		
		true_br_seq(pos+1, op_br_cnt-1);
		
		s.push('(');
		res[pos] = ' ';
	}
}

int main()
{
	input();
	
	true_br_seq(0, 0);
	
	cout << cnt;
	
	return 0;
}
