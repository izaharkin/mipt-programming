#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int z = 7;
	int *p1 = &z;
	
	cout << p1 << " " << *p1 << "\n";
/////////////////////////////////////////
	int n = 7;
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = (1 << i);
	int *p2 = arr;	
	
	cout << p2 << " ";
	for (int i = 0; i < n; i++)
		cout << *(p2 + i) << " ";
	cout << "\n";
/////////////////////////////////////////
	int *p3 = p2;
	p2 = p1;
	p2 = p3;

	cout << p1 << " " << p2 << "\n";
	cout << *p1 << " ";
	for (int i = 0; i < n; i++)
		cout << p2[i] << " ";

	delete p1;
	delete [] p2;
	delete [] p3;
/////////////////////////////////////////
	n = 10;
	int arr1[n], arr2[n];
	p1 = arr1;
	for (int i = 0; i < n; i++)
		p1[i] = (1 << i);
	
	p2 = arr2;
	p2 = p1;
/////////////////////////////////////////
	vector <int> vec1(10), vec2(10);
	for (int i = 0; i < n; i++)
		vec1[i] = (1 << i);
		
	vec2 = vec1;

	return 0;
}
