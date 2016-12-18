#include <iostream>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	bool flag = true;
	for (int i = 2; i*i <= n && flag; i++)
		if ( n % i == 0 )
			flag = false;
			
	cout << (flag ? "Prime" : "Composite");
	
	return 0;
}
