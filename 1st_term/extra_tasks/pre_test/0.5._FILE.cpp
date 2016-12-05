#include <iostream>

using namespace std;

int main()
{
	int x;
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	while ( cin >> x ) 
		cout << x << " ";
	
	return 0;
}
