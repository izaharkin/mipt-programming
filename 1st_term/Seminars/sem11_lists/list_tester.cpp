#include "list_tester.h"

using namespace std;

bool ListTester:: check_length (const List& ls, const int nelems)
{
	int count = 0;
	Item *q = 0;
	
	//forward pass
	count = 0;
	for (Item *p = ls.head; p != 0; p = p->next)
	{
		q = p;
		++count;
	}
	if ( nelems != count || q != ls.tail )
		return false;
		
	//backward pass
	count = 0;
	for (Item *p = ls.tail; p != 0; p = p->prev)
	{
		q = p;
		++count;
	}
	if ( nelems != count || q != ls.head )
		return false;
	
	return true;
}

bool ListTester:: test_new_list ()
{
	List ls;
	
	if ( ls.head != 0 || ls.tail != 0 )
		return false;
		
	return true;
}

bool ListTester:: test_push_front ()
{
	List ls;
	
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		ls.push_front(i);
		if ( ls.tail->val != 0 )
			return false;
		if ( ls.head->val != i )
			return false;
	}	
	
	if ( !check_length(ls, n) )
		return false;
		
	i = n;
	for (Item *p = ls.head; p != 0; p=p->next)
		if ( p->val != --i ) return false;
		
	i = 0;
	for (Item *p = ls.tail; p != 0; p=p->prev)
		if ( p->val != i++ ) return false;
	
	return true;
}

bool ListTester:: test_push_back ()
{
	List ls;
	
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		ls.push_back(i);
		if ( ls.tail->val != i )
			return false;
		if ( ls.head->val != 0 )
			return false;
	}	
	
	if ( !check_length(ls, n) )
		return false;
		
	i = 0;
	for (Item *p = ls.head; p != 0; p=p->next)
		if ( p->val != i++ ) return false;
		
	i = n;
	for (Item *p = ls.tail; p != 0; p=p->prev)
		if ( p->val != --i ) return false;
	
	return true;
}

bool ListTester:: mem_leak()
{
	for (;;)
	{
		{
			List ls;
		}
	}	
} 

void ListTester:: run (const string& name, 
					   bool (*test) (void) )
{
	cout << "run " << setw(18) << left << name << flush;
	if ( test() )
		cout << "[OK]\n";
	else
	{
		cout << "[FAILED]\n";
		//error("last test must not continue");
	}
}


