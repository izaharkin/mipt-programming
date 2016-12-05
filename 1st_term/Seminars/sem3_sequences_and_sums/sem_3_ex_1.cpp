#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> t(1);
	int tmp;
	
	while ( cin >> tmp )
		t.push_back(tmp), t[0] += tmp;
	
	cout << t[0] / (t.size()-1) << '\n';
}
