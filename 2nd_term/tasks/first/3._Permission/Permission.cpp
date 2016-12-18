#include "Permission.h"

bool Study_B::Permission(const Human* h)
{
	bool flag = false;

	const Student* is_st = dynamic_cast <const Student*> (h);
	if (is_st != NULL)  // if it is a student
	{
		flag = true;
	}
	else                  // if it is a worker
	{
		const Worker* is_w = dynamic_cast <const Worker*> (h);
		if (is_w != NULL)
			flag = true;
	}

	return flag;
}

void Lab::GivePermission(Student *st)
{
	has_perm.push_back(st);
}

bool Lab::Permission(const Human* h)
{
	bool flag = false;

	const Student* is_st = dynamic_cast <const Student*> (h);
	if (is_st != NULL) // if it is a student
	{
		for (vector <Student*>::iterator i = has_perm.begin(); i != has_perm.end(); ++i)
		if (*i == is_st)
			flag = true;
	}
	else                 // if it is a worker
	{
		const Worker* is_w = dynamic_cast <const Worker*> (h);
		if (is_w != NULL)
			flag = true;
	}

	return flag;
}