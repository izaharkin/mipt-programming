#include <iostream>
#include <vector>

using namespace std;

vector <int> get_primes (int n)
{
	vector <int> pr;
	
	if ( n < 2 )
		throw n;
	
	for (int i = 2; i <= n; i++)
	{
		if ( !pr.size() )
		{
			pr.push_back(i);
			continue;
		}
		bool flag = true;
		for (int j = 0; j < pr.size() && flag; j++)
		{
			if ( !(i % pr[j]) )
				flag = false;
		}
		if ( flag )
			pr.push_back(i);
	}
	
	return pr;
}

int main()
{
	int n;
	
	cin >> n;
	
	try
	{
		vector <int> p = get_primes(n);
	
		for (int i = 0; i < p.size(); i++)
			cout << p[i] << ' ';
	}
	catch (int i)
	{
		cout << "Wrong value of maximal prime number (n = " << i << ")\n";
	}
	
	return 0;
}
