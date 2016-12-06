#include "Students.h"

string Student::getSurname() const
{
	return surname;
}

bool operator < (const Student& a, const Student& b)
{
	return (a.getSurname() < b.getSurname());
}

bool Student::reprove(const string& course) const
{
	map<string, int>::const_iterator i = marks.find(course);
	if (i != marks.end())
		return (i->second == 0);
	return false;
}

bool Student::unsat(const int k) const
{
	int cnt = 0;
	for (map<string, int>::const_iterator i = marks.begin(); i != marks.end(); i++)
		if (i->second > 2)
			cnt++;

	return (cnt < k);
}

void Group::add(const Student& st)
{
	gr.insert(st);
}

vector<string> Group::getReprovers(const string& course) const
{
	vector <string> vec;

	for (set<Student>::iterator i = gr.begin(); i != gr.end(); ++i)
	{
		if (i->reprove(course))
			vec.push_back(i->getSurname());
	}

	return vec;
}

void Group::popBadStudents(const int k)
{
	vector <set<Student>::iterator> del;

	for (set<Student>::iterator i = gr.begin(); i != gr.end(); ++i)
		if (i->unsat(k))
			del.push_back(i);
	
	for (size_t i = 0; i < del.size(); ++i)
		gr.erase(del[i]);
}

void Group::show() const
{
	for (set<Student>::iterator i = gr.begin(); i != gr.end(); ++i)
		cout << i->getSurname() << "\n";
}

