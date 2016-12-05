#include <iostream>

using namespace std;

class FirstClass
{
protected: // видно себе и только наследникам
	int value;
public:
	FirstClass() : value(0) {}
	FirstClass(int a) : value(a) {}
	void show_value () const
	{
		cout << value << "\n";
	}
	// ¬иртуальна€ функци€
	virtual void Put_Value (int a)
	{
		value = a;
	}
};

/* “ипы наследовани€:
	private,   - все protected и public базового перейдут перейдут в private наследника
	protected, - все protected и public базового перейдут перейдут в protected наследника
	public     - все protected и public базового перейдут перейдут в protected и public наследника
*/
class SecondClass: public FirstClass
{
public:
	SecondClass (): FirstClass () {}
	SecondClass (int b): FirstClass (b) {}
	void show_value() const
	{
		FirstClass:: show_value();
	}
	void Put_Value (int a)
	{
		value = a*a;
	}
};

// јбстрактные классы - классы, созданные только дл€ того, чтобы их наследовали

int main()
{
	
	
	return 0;
}
