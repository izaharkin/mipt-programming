#include <iostream>

using namespace std;

int main()
{
	int var = 0;
	int *pi = &var;
	
	cout << pi << " " << *pi << "\n";
	*pi = 27;
	cout << var;
///////////////////////////////////////////	
	char ch1 = 'a', ch2 = 'b', ch3 = 'c', ch4 = 'd';
//	int *ppi = &ch3;
	
//	*ppi = 12345;
//	*ppi = 98765; - взорвёт компьютер :)

	cout << "\n" << sizeof(long double);
	
	int *p = new int[10];
	
//  *(p + k) == p[k]

	delete [] p; 
	p = 0;         // если не конец программы
	
	return 0;
}
