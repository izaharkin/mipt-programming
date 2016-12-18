#include "Smart_Ptr.h"

int main()
{
	int i = 15;
	int *b = &i;
	smart_ptr <int> a(b);

	cout << *a;

	system("PAUSE");

	return 0;
}