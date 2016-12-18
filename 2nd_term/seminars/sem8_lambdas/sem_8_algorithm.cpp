/*
------------- <algorithm> -----------
void sort(RAI first, RAI last, Comp c);
bool is_sorted(FI first, FI last, Comp c);
min();
max();
iterator min_element(FI first, FI last, Comp c);
bool lexicographical_compare(f1, l1, f2, l2, c);
bool equal(f1, l1, f2, c);
OI copy (II first, II last, OI res);
OI back_insert(container& x) // сама делает push_back()
reverse(BI first, BI last);
random_shuffle();
for_each(II first, II last, LAMBDA);
generate(FI first, FI last, Generator gen);
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> v(10);
	int n = v.size();
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	for_each(v.begin()), v.end(), 
		[](){
			
	});
	
	return 0;
}
