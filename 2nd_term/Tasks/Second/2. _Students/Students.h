#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*
�������� ������ ������ � �������. 
������ ������� �� std::set ���������. 
� �������� ���� ������������� ������ std::map �������� ����� - ������. 
�������� �����, ������� ������ ������ ������� ��������� � ���������� �� ������������� ����� (�������� ������) � �����, 
������� �������� ���, � ���� ���������� ������� ��������� �� ������������������ ������ ����� k.
*/
class Student
{
private:
	map <string, int> marks; // 0 - reprove
	string surname;
public:
	Student() : marks(), surname("") {}
	Student(const map<string, int>& m, const string& s) : marks(m), surname(s) {}
	Student(const Student& st) : marks(st.marks), surname(st.surname) {}

	string getSurname() const;
	bool reprove(const string&) const;
	bool unsat(const int) const;

	friend bool operator < (const Student& a, const Student& b);
};

class Group
{
private:
	set <Student> gr;
public:
	Group() : gr() {}
	Group(const Group& G) : gr(G.gr) {}

	void add(const Student&);
	void show() const;

	vector<string> getReprovers(const string&) const;
	void popBadStudents(const int);
};