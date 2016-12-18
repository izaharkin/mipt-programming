#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n;
vector <int> prior;
bool used[1001] = {false};

struct pairr
{
	int a, b;
};

struct comp
{
	string ss;
	int num;	
};

int find_min (vector <pairr> v, int l, int r)
{
	int i_min = l;
	
	for (int i = l+1; i < r; i++)
		if ( v[i].a < v[i_min].a ) 
			i_min = i;
	
	return i_min;
}

bool all()
{
	for (int i = 0; i < n; i++)
		if ( !used[i] ) return false;
	return true;
}

int countm = 0;
void matrix_min_multiply (vector <pairr> temp, int l, int r)
{
	cout << ">" << countm++ << " " << l << " " << r << "\n";
	
	if ( all() ) 
	{
		cout << "!" << --countm << "\n";
		return;
	}
	
	int i_min = find_min(temp, l, r);  // ищем минимум
	cout << i_min << "\n";
	if ( !used[i_min] ) 
	{
		prior.push_back(i_min+1);
		used[i_min] = true;
	}
	
	int i;
	bool flag = false;
	for (i = i_min+1; i < r && !flag; i++)
		if ( !used[i] ) 
		{
			cout << i << "-used\n";
			flag = true;
			break;
		}

	if ( flag )
	{
		used[i] = true;
		prior.push_back(i+1);
		matrix_min_multiply(temp, i_min, r);
		matrix_min_multiply(temp, l, i_min);
	}
		
	cout << "<" << --countm << " " << l << " " << r << "\n";
}

bool operator < (comp s1, comp s2)
{
	return s1.num < s2.num;
}

int main()
{
	cin >> n;
	vector <int> p(n+1);
	for (int i = 0; i < n+1; i++)
		cin >> p[i];
		
	vector <pairr> temp(n);
	for (int i = 0; i < n; i++)
	{
		temp[i].a = p[i];
		temp[i].b = p[i+1];
	}
	
	matrix_min_multiply(temp, 0, n);
	
	comp s[1001];
	for (int i = 0; i < 1001; i++)
		s[i].ss = "";
		
	for (int i = 0; i < n; i++)
		cout << prior[i] << " ";
	cout << "\n";
	
	int k(0), i(0);
	while ( i < n-1 )
	{
		while ( i < n-1 && prior[i] < prior[i+1] )
		{
			if ( s[k].ss == "" )
			{
				s[k].ss = string("A") + char('0'+char(prior[i])) + " x " + "A" + char('0'+char(prior[i+1]));
				s[k].num = prior[i];
			}
			else
				s[k].ss = string("(") + s[k].ss + ")" + " x " + "A" + char('0'+char(prior[i+1]));
			i++;
		}
		k++;
		i++;
	}
	
	sort(s, s+k);
	
	for (int i = 0; i < k; i++)
	{
		cout << '(' << s[i].ss << ')';
		if ( i != k-1 )
			cout << " x ";		
	}
	
	return 0;
}
