#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct seg
{
	int s, f;	
};

bool operator < (seg a, seg b)
{
	return a.f < b.f;
}

int main()
{
	int n;
	vector <seg> p;
	
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].s >> p[i].f;
		
	sort(p.begin(), p.end());
	
	int cnt = 1;
	int cur_f = p[0].f;
	cout << p[0].s << " " << p[0].f << "\n";
	for (int i = 1; i < n; i++)
		if ( p[i].s >= cur_f )
		{
			cnt++;
			cur_f = p[i].f;
			cout << p[i].s << " " << p[i].f << "\n";
		}
	cout << cnt;
	
	return 0;
}
