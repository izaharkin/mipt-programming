#include "BigInt.h"

// I made vector instead of array, factorial works well, all the operators too
int main()
{
	bigint a, b, c;

	cin >> a;
	cin >> b;

	c = a + b;
	cout << c;

	if (a > b) c = a - b;
	else         c = b - a;
	cout << c;

	bool sign = false;
	c = subtract(a, b, sign);
	if (sign) cout << '-';
	cout << c;

	c = a * b;
	cout << c;

	c = a / b;
	cout << c;

	c = a % b;
	cout << c;

	cout << fact(1000);

	system("PAUSE");

	return 0;
}