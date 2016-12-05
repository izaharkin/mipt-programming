#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

typedef stack<int> sti;

int main ()
{
	int k;
	stack <int> st;
	vector< vector <sti> > ans; // элементы матрицы - стеки
	
	cin >> k;
	
	int n = pow(2, k);
	ans.resize(n+2);
	for (int i = 0; i <= n+1; i++)
		ans[i].resize(n+2);
	
	for (int i = 1; i <= pow(4, k); i++)
		st.push(i);
	
	ans[1][1] = st;	
	
	// делим исходный стек i раз/ В итоге получим на 4^k стеков
	for (int i = 1; i <= 2*k; i++)
	{
		if ( i & 1 ) // если это нечётное деление, то получаются 2^(i-1) новых стеков вниз
		{
			for (int j = 1; j <= pow(2, i-1); j++)
			{
				for (int l = 1; l <= pow(2, i-1); l++) // количество новых стеков
				{
					for (int k = 1; k <= (ans[j][l].size() >> 1); k++)
					{
						ans[j+i-2*(j-1)][l].push(ans[j][l].top());
						ans[j][l].pop();
					}
				}
			}
		}
		else         // если это чётное деление, то получаются 2^(i-1) новых стеков вправо
		{
			int ii = i-1;
			for (int j = 1; j <= pow(2, ii-1); j++)
			{
				for (int l = 1; l <= pow(2, i-1); l++) // количество новых стеков
				{
					for (int k = 1; k <= (ans[l][j].size() >> 1); k++)
					{
						ans[l][j+ii-2*(j-1)].push(ans[l][j].top());
						ans[l][j].pop();
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << ans[i][j].top() << " ";
		cout << "\n";
	}
	
	return 0;
}
