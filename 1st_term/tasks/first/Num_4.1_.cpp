#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct atlet
{
	int p; // power
	int w; // weight
};

bool operator < (const atlet& a, const atlet& b)
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
		cin >> a[i].p >> a[i].w; 
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++)
		cout << a[i].p << " " << a[i].w << "\n";
	
	return 0;
}
