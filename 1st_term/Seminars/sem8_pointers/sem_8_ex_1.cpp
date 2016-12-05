#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print_array10 (ostream& os, int* a)
{
	for (int i = 0; i < 10; i++)
		os << *(a + i) << " "; 
	cout << "\n";
}

void print_array (ostream& os, int* a, int n)
{
	for (int i = 0; i < n; i++)
		os << *(a + i) << " "; 
	cout << "\n";
}

void print_vector (ostream& os, vector <int> vec)
{
	for (vector <int>::iterator i = vec.begin(); i != vec.end(); i++)
		os << *i << " ";
	cout << "\n";
}

int main()
{
	int *arr = new int[10];
	
	for (int i = 0; i < 10; i++)
		cout << *(arr + i) << " ";
	cout << "\n";
	
	print_array10 (cout, arr);
	
	delete [] arr;
/////////////////////////////////////////	
	arr = new int[10];
	for (int i = 0; i < 10; i++)
		*(arr + i) = 100 + i;
	print_array10(cout, arr);
	
	delete [] arr;
/////////////////////////////////////////	
	arr = new int[11];
	for (int i = 0; i < 11; i++)
		*(arr + i) = 100 + i;
	for (int i = 0; i < 11; i++)
		cout << *(arr + i) << " ";
	cout << "\n";
	
	delete [] arr;
/////////////////////////////////////////	
	arr = new int[20];
	for (int i = 0; i < 20; i++)
		*(arr + i) = 100 + i;
	print_array(cout, arr, 20);
	
	delete [] arr;
/////////////////////////////////////////
	int n = 10;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = 100 + i;
	print_vector(cout, a);
/////////////////////////////////////////	
	n = 11;
	a.resize(n);
	for (int i = 0; i < n; i++)
		a[i] = 100 + i;
	print_vector(cout, a);
/////////////////////////////////////////
	n = 20;
	a.resize(n);
	for (int i = 0; i < n; i++)
		a[i] = 100 + i;
	print_vector(cout, a);
	
	return 0;
}
