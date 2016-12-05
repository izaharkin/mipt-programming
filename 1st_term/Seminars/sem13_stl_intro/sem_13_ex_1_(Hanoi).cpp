#include <iostream>
#include <stack>

using namespace std;

// Нужно переложить все диски с первого на третий столбец (с А на С)

void Hanoi (int n, int a, int b, int c)
{
	if ( n == 0 )
		return;
		
	if ( n == 1 )
	{
		cout << "1 " << a << " " << b << "\n";
	}
	else
	{
		Hanoi(n-1, a, c, b);
		cout << n << " " << a << " " << b << "\n";
		Hanoi(n-1, c, b, a);
	}
}

int main()
{
	int n;
//	stack a, b, c;
	
	cin >> n;
	/*
	for (int i = n; i >= 1; i--)
		a.push(i);
	*/
	Hanoi(n, 1, 2, 3);
	
	return 0;
}
