// —“–¿”—–”œ. √À¿¬¿ 9.
#include <iostream>
#include <iomanip>

#ifndef LIST
#define LIST

using namespace std;

template <class T>
struct Item
{
	T val;
	Item* prev;
	Item* next;
	
	Item (T n) : val(n), prev(0), next(0) {}
};

template <class T>
class List
{
private:
	Item <T>* head;
	Item <T>* tail;
public:
	List () : head(0), tail(0) {}
	
	~List ()
	{
		clear();	
	}
	
	void push_back  (T val);
	void push_front (T val);
	void pop_back   (T& val);
	void pop_front  (T& val);
	
	void reverese   ();
	void clear ();
	bool is_empty () const
	{
		return head == 0;
	}
	
	friend class ListTester;
private:
	List              (const List&);
	List& operator =  (const List&);
	friend void print (ostream&, const List&, const char*);
};

#endif
