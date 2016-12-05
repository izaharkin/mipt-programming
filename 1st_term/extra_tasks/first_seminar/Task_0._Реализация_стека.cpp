#include <iostream>
#include <fstream>

using namespace std;

template <class T>
struct elem
{
	T info;
	elem <T>* next;
};

template <class T>
class Stack
{
private:
	elem <T>* head;
	int sz;	
public:
	Stack  ();
	~Stack ();
	
	void Push (T);
	T    Pop  ();
	T    Top  ();
	
	int Size   ();
	void Clear ();
	bool Empty ();
};

template <class T>
Stack <T>:: Stack ()
{
	head = NULL;
	sz = 0;
}

template <class T>
Stack <T>:: ~Stack ()
{
	Clear();
}

template <class T>
void Stack <T>:: Push (T x)
{
	elem <T>* temp = new elem <T>;
	temp->info = x;
	
	if ( head != NULL )
		temp->next = head;
	head = temp;
	
	sz++;
}

template <class T>
T Stack <T>:: Pop ()
{
	if ( head == NULL )
		return 0;
		
	T x = head->info;
		
	elem <T>* p = head;
	head = head->next;
	
	delete p;
	sz--;
	
	return x;
}

template <class T>
T Stack <T>:: Top ()
{
	return head->info;
}

template <class T> 
int Stack <T>:: Size ()
{
	return sz;
}

template <class T> 
void Stack <T>:: Clear ()
{
	while ( sz ) Pop();
}

template <class T> 
bool Stack <T>:: Empty ()
{
	return sz == 0;
}

/*
template <class T> 
int Stack <T>:: GetElem (int n)
{
	if ( n > sz ) 
		return 0;
		
	if ( n == 1 )
		return Pop();
	
	elem <T>* p = head;
	for (int i = 0; i < n-1; i++)
		p = p->next;
	
	p->next 
}
*/
int main ()
{
	Stack <int> st;
	
	ifstream ifs("in.txt");
	
	int x;
	while ( ifs >> x ) st.Push(x);
	
	//close(ifs);
	
	ofstream ofs("out.txt");
	while ( !st.Empty() )
		cout << st.Pop() << "\n";
	
	//close(ofs);
	
	return 0;
}
