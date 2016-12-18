#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<double, double> m;
	
	m.insert(make_pair(5.5, 6.0));
	
	map<double, double>::iterator it = m.find(5.0);
	cout << it->second;
	
//	it->first = 1555;
	
	map<double, double>::iterator iter = m.find(600.56);
	cout << iter->second;
	
	return 0;
}
