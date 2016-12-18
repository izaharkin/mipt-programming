// gafrustam@gmail.com
#include <iostream>
#include <string>

class Human
{
protected:
	std::string name;
	std::string surname;
public:
	Human (const std::string& _name, const std::string& _surname): name(_name), surname(_surname) {}
	virtual void getTitle () const
	{
		std::cout << "Good day, ";
	}
	virtual ~Human() {}
};

class Mister: public Human
{
public:
	Mister (const std::string& nm, const std::string& snm): Human(nm, snm) {}
	void getTitle () const
	{
		Human::getTitle();
		std::cout <<  "Mr. " << surname << "\n";
	}
};

class Miss: public Human
{
public:
	Miss (const std::string& nm, const std::string& snm): Human(nm, snm) {}
	void getTitle () const
	{
		Human::getTitle();
		std::cout << "Miss " << surname << "\n";
	}
};

class Child: public Human
{
public:
	Child (const std::string& nm, const std::string& snm): Human(nm, snm) {}
	void getTitle () const
	{
		Human::getTitle();
		std::cout << name << "\n";
	}
};

int main()
{
	std::string name, surname;
	
	std::cout << "Enter Mister: ";
	std::cin >> name >> surname;
	Mister Mr (name, surname);
	
	std::cout << "Enter Miss: ";
	std::cin >> name >> surname;
	Miss Ms (name, surname);
	
	std::cout << "Enter child: ";
	std::cin >> name >> surname;
	Child Kid (name, surname);
	
	Mr.getTitle();
	Ms.getTitle();
	Kid.getTitle();
	
	return 0;
}
