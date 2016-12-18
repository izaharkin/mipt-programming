#include <iostream>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	cout << 1 + (n / 20) - (n % 20 == 0 ? 1 : 0);
	
	return 0;
}
