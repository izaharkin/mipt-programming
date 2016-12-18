#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count = 0;

	vector <int> v(10);
	for (int i = 0; i < 10; ++i)
		v.push_back(10 - i);

	function <bool(int, int)> f = [&count](int l, int r) {
		count++;
		return l < r;
	};

	sort(v.begin(), v.end(), f);
	cout << count << '\n';

	for (int i = 0; i < 10; ++i)
		v.push_back(i + 3);

	sort(v.begin(), v.end(), f);
	cout << count << '\n';

	system("PAUSE");

	return 0;
}