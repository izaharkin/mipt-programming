#include <iostream>

using namespace std;

f (const string& s)
{
	const_cast <string&> (s).method_that_changes_s();
}

int main()
{
	T1* t;
	T2* t2 = static_cast <T2*> (t); // ���������� ���� �� ����� ����������, �����������
	
	T2* t2 = dynamic_cast <T2*> (t); // ���������� ���� �� ����� ����������, ������������, 
								     // �� ������ NULL, ���� �� ���������� ��������
								     // � ������� ���� ����� ������, ���������� ������� ����� � ������������ ��� ���
	T2* t2 = reinterpret_cast  <T2*> (t); // ���������� ���
	
	T2 t2 = const_cast <T2> (t); // ������� ������������� � �������
	
	return 0;
}
