#include <iostream>
#include <string>

int main ()
{
	string s;
	
	s.find(t, i);  // ����� ������ ������� �������� ������ s, ����� �������� ���������� ��������� t ������� �� ������, ������� � �������� � �������� i
	string:: npos; // ������������ ������ ������
	s.rfind();     // ��������� ���������
	
	s.find_first_of(string t);      // ������ ��������� ������ �� ��������� t � s (����� ����������)
	s.find_first_not_of(string t);  // ������ ����������� ��������� t � s
	
	s.compare(string t); // ���������
	s.c_str(); // ������������ � ������ � ����� �
	
	return 0;
}
