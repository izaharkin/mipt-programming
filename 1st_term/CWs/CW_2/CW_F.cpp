#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main ()
{
	vector <float> a, b;
	bool flag[1000] = {false};
	
	float x;
	while ( cin >> x ) 
		a.push_back(x);
	
	int n = a.size();
	for (int i = 0; i < n; i++)
		if ( a[i] > 0 )
		{
			b.push_back(a[i]);
			flag[i] = true;
		}
	
	sort(b.begin(), b.end());
	
	int k = 0;
	for (int i = 0; i < n; i++)
		if ( flag[i] )
			a[i] = b[k++];

	for (int i = 0; i < n; i++)
		printf("%.3f ", a[i]);
	
	return 0;
}
