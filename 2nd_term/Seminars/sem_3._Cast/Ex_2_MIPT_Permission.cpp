#include <iostream>

using namespace std;

class Human
{
protected:
	string name;
	string surname;
public:
	Human (const string& _name, const string& _surname): name(_name), surname(_surname) {}
	virtual ~Human() {}
};

class Student: public Human
{
public:
	bool has_perm;
	Student (const string& _name, const string& _surname): Human(_name, _surname), has_perm(false) {}
	bool HasPerm () const
	{
		return has_perm;
	}
};

class Worker: public Human
{
public:
	Worker (const string& _name, const string& _surname): Human(_name, _surname) {}
};

class Building
{
public:
	virtual bool Permission (const Human* h) {}
};

class Study_B
{
public:
	bool Permission (const Human* h)
	{
		bool flag = false;
		
		const Student* is_st = dynamic_cast <const Student*> (h); 
		if ( is_st != NULL )  // if it is a student
		{
				flag = true;
		}
		else                  // if it is a worker
		{
			const Worker* is_w = dynamic_cast <const Worker*> (h);
			if ( is_w != NULL )
				flag = true;
		}
		
		return flag;
	}	
};

class Lab: public Building
{
public:
	void GivePermission (Student *st)
	{
		st->has_perm = true;
	}
	
	bool Permission (const Human* h)
	{
		bool flag = false;
		
		const Student* is_st = dynamic_cast <const Student*> (h); 
		if ( is_st != NULL ) // if it is a student
		{
			if ( is_st->HasPerm() )
				flag = true;
		}
		else                 // if it is a worker
		{
			const Worker* is_w = dynamic_cast <const Worker*> (h);
			if ( is_w != NULL )
				flag = true;
		}
		
		return flag;
	}
};

int main()
{
	Human hh("a", "b");
	Student stt("a", "b"), st_pp("a", "b");
	Worker ww("a", "b");
	
	Human *h = &hh;
	Student *st = &stt, *st_p = &st_pp;
	Worker *w = &ww;
	
	Study_B GK;
	Lab L;
	
	L.GivePermission(st_p);
	
	cout << GK.Permission(h) << " ";
	cout << GK.Permission(st) << " ";
	cout << GK.Permission(st_p) << " ";
	cout << GK.Permission(w) << "\n";
	
	cout << L.Permission(h) << " ";
	cout << L.Permission(st) << " ";
	cout << L.Permission(st_p) << " ";
	cout << L.Permission(w) << "\n";
	
	return 0;
}
