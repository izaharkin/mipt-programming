// Безопасные преобразования:
// bool -> char, int, double (float)
// char -> int, double (float)
// int -> double (float)
#include <iostream>

using namespace std;

int main()
{
	char c1 = 'x'; // выведет 'x'
	int i1 = c1;   // выведет номер из ASCII
	int i2 = 'x';  // выведет номер из ASCII
	char c2 = i1;  // выведет 'x'
	
	cout << c1 << ' ' << i1 << ' ' << i2 << ' ' << c2 << '\n';
	
	int a = 20000;
	char c = a;
	int b = c;
	
	if ( a != b )
		cout << "Oops!: " << a << " != " << b << '\n';
	else
		cout << "Wow! We have large characters!\n";
	
	return 0;
}
