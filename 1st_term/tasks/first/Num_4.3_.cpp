#include <iostream>
#include <vector>

using namespace std;

int a[1001][10001], w[1001], p[1001];
vector <int> ans;

void find_ans (int k, int s)
{
	if ( a[k][s] == 0 )
		return;
		
	if ( a[k][s] = a[k-1][s] )
		find_ans(k-1, s);
	else
	{
		find_ans(k-1, s-w[k]);
		ans.push_back(k);
	}
}

int main()
{
	int n, W;
	
	cin >> n >> W;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> p[i];
	
	for (int i = 0; i <= n; i++)
		a[i][0] = 0;
	
	for (int i = 0; i <= W; i++)
		a[0][i] = 0;

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= W; s++)
			if ( s >= w[k] )
				a[k][s] = max( a[k-1][s], a[k][s-w[k]] + p[k] );
			else
				a[k][s] = a[k-1][s];
	}
	
	cout << a[n][W] << "\n";
	
	find_ans(n, W);
	
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	
	return 0;
}
