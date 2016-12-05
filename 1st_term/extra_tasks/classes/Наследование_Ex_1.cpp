#include <iostream>

using namespace std;

class Base
{
public:
	void iam ()
	{
		cout << "Base\n";
	}
};

class Base1: public Base
{
public:
	void iam ()
	{
		cout << "Base1\n";
	}
};

class Base2: public Base
{
public:
	void iam ()
	{
		cout << "Base2\n";
	}
};

int main()
{
	Base1 B1;
	Base2 B2;
	Base* pB1 = &B1;
	Base* pB2 = &B2;
	
	pB1->iam();
	pB2->iam();
	
	return 0;
}
