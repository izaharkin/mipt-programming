#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int merge (vector <int>& a, int l, int m, int r)
{
	int inv = 0;
	
	vector <int> buf(r - l + 1);
	
	int pos1 = l;
	int pos2 = m+1;
	int posB = 0;
	
	while ( pos1 <= m && pos2 <= r )
	{
		if ( a[pos1] < a[pos2] ) buf[posB++] = a[pos1++];
		else                     
		{
			inv += m - pos1 + 1;
			buf[posB++] = a[pos2++];
		}
	}
	
	while ( pos1 <= m ) 
		buf[posB++] = a[pos1++];
	
	while ( pos2 <= r ) 
		buf[posB++] = a[pos2++];
	
	copy(buf.begin(), buf.end(), a.begin() + l);
	buf.clear();
	
	return inv;
}

int merge_sort (vector <int>& a, const int& l, const int& r)
{
	int cnt = 0;
	
	if ( l == r ) 
		return 0;
	
	int m = (l + r) >> 1;
	
	cnt += merge_sort(a, l, m);
	cnt += merge_sort(a, m+1, r);
	
	cnt += merge(a, l, m, r);
	
	return cnt;
}

int main()
{
	int n;
	vector <int> a;
	
	scanf("%d", &n);
	a.resize(n);
	
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	
	int ans = merge_sort(a, 0, a.size()-1);
	
	cout << ans;
	
	return 0;
}
