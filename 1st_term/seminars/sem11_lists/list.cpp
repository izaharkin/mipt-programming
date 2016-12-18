#include "list.h"

using namespace std;

template <class T>
void print (ostream& os, const List <T>& ls, const char* end = "\n")
{
	for (Item <T>* p = ls.head; p != 0; p = p->next)
		os << p->val << (p->next ? " " : end);
}

template <class T>
void List <T>:: push_front (T val)
{
	Item <T>* item = new Item <T> (val);
	
//	if ( !item ) cerr << ("Can`t allocate memory");
	
	if ( !head ) 
		head = tail = item;
	else
	{
		item->next = head;
		head->prev = item;
		head = item;
	}
}

template <class T>
void List <T>:: pop_front (T& rval)
{
//	if ( !head ) cerr << ("Try to pop from an empty list");
	
	Item <T>* item = head;
	head = item->next;
	
	if ( !head )
		tail = head;
	else
		head->prev = 0;
		
	rval = item->val;
	
	delete item;
}

template <class T>
void List <T>:: push_back (T val)
{
	Item <T>* item = new Item <T> (val);
	
	//	if ( !item ) cerr << ("Can`t allocate memory");
	
	if ( !head )
		head = tail = item;
	else
	{
		item->prev = tail;
		tail->next = item;
		tail = item;
	}
}

template <class T>
void List <T>:: pop_back (T& rval)
{
//	if ( !head ) cerr << ("Try to pop from an empty list");
	
	Item <T>* item = tail;
	tail = item->prev;
	
	if ( !tail )
		head = tail;
	else
		tail->next = 0;
		
	rval = item->val;
	
	delete item;
}

template <class T>
void List <T>:: clear ()
{
	Item <T>* p = head;
	
	while ( p = p->next )
	{
		delete p->prev;
	}
	delete tail;
	
	head = tail = 0;
}
