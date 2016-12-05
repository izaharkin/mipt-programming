#include <iostream>

using namespace std;

class FirstClass
{
protected: // ����� ���� � ������ �����������
	int value;
public:
	FirstClass() : value(0) {}
	FirstClass(int a) : value(a) {}
	void show_value () const
	{
		cout << value << "\n";
	}
	// ����������� �������
	virtual void Put_Value (int a)
	{
		value = a;
	}
};

/* ���� ������������:
	private,   - ��� protected � public �������� �������� �������� � private ����������
	protected, - ��� protected � public �������� �������� �������� � protected ����������
	public     - ��� protected � public �������� �������� �������� � protected � public ����������
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

// ����������� ������ - ������, ��������� ������ ��� ����, ����� �� �����������

int main()
{
	
	
	return 0;
}
