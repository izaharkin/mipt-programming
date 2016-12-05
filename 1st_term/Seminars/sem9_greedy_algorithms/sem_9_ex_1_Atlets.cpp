#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct atlet
{
	int w, p;	
};

bool operator < (atlet a, atlet b)
{
	return a.p < b.p;
}

int main()
{
	int n;
	vector <atlet> a;
	
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].w >> a[i].p;
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++)
		cout << a[i].w << " " << a[i].p << " ";
	
	return 0;
}
