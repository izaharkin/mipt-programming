#ifndef _PERMISSION_H_

#define _PERMISSION_H_

#include <iostream>
#include <vector>

using namespace std;

class Human
{
protected:
	string name;
	string surname;
public:
	Human(const string& _name, const string& _surname) : name(_name), surname(_surname) {}
	virtual ~Human() {}
};

class Student: public Human
{
public:
	Student(const string& _name, const string& _surname) : Human(_name, _surname) {}
};

class Worker: public Human
{
public:
	Worker(const string& _name, const string& _surname) : Human(_name, _surname) {}
};

class Building
{
public:
	virtual bool Permission(const Human* h) = 0;
};

class Study_B: public Building
{
public:
	bool Permission(const Human* h);
};

class Lab: public Building
{
protected:
	vector <Student*> has_perm;
public:
	void GivePermission(Student *st);
	bool Permission(const Human* h);
};

#endif /* _PERMISSION_H_ */
