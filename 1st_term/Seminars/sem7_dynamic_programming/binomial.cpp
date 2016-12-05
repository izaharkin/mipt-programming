// ÃËÀÂÀ 4 - 1
// ÃËÀÂÀ 15
#include <iostream>
#include <vector>

using namespace std;

void binomial (vector <int>& res, int n)
{
	if ( res.size() < size_t(n+1) )
		res.resize(n+1, 0);
	
	res[n] = 1;
	
	if ( n == 0 ) return;
	
	binomial(res, n-1);
	for (int i = n-1; i > 0; i--)
		res[i] += res[i-1];
	
	return;
}

int main()
{
	int n;
	
	cin >> n;
	
	vector <int> ans;
	binomial(ans, n);
	
	for (int i = 0; i <= n; i++)
		cout << ans[i] << " ";	
	
	return 0;
};
