#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, nn, num;
	
	cin >> n >> m;
	
	vector <char> a(n, false);
	
	nn = n;
	while ( nn > 0 )
	{
		num = m % nn;
		a[((num == 0) ? (a[nn-1] ?  ): num-1+a[num-1])] = true, nn--;
		if (  )
	}

	return 0;
}
