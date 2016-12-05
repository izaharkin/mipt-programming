#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Person
{
protected:
	string name, sec_name, fath;
public:
	virtual void show_data ()
	{
		cout << sec_name << " " << name << " " << fath << "\n";
	}
};

class Student: public Person
{
protected:
	int age;
	int average_point;
public:
	void show_data ()
	{
		Person:: show_data();
		cout << "Age: " << age << "\n";
		cout << "AP: " << average_point << "\n";
	}
};

class Professor
{
protected:
	int age;
	string profession;
	int publication_quantity;
public:
	void show_data ()
	{
		Person:: show_data();
		cout << "Age: " << age << "\n";
		cout << "Profession: " << profession << "\n";
		cout << "Publications: " << publication_quantity << "\n";
	}
};

int main()
{
	
	
	return 0;
}
