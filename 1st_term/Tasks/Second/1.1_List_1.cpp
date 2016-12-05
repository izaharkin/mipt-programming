#include <iostream>
#include <cstdio>

using namespace std;

struct elem
{
	int info;
	elem* next;
};

class List
{
private:
	elem* head;
	int size;
	
public:
	List() : head(0), size(0) {}
	
	List list_new    ();               // ������� ����� ������
	void list_delete ();         // ������� ������ l � ��� ��� ��������
	void insert      (int a);  // �������� ������ � �������� ������ ������ � � ������ ������ l
	void remove      (int a);  // ������� �� ������ ��� ��������, ���������� �������� ����� ����� �
	void print       ();         // ������� ��������, ���������� � ��������� ������ l
// ��������������� �������:
	int  search   (int a);  // ����� ������� � �������� ��������� (������ ���������)
	void del_pos  (int k);  // ������� ������� � �������� ������� 
	void del      ();         // ������� ������ ������� ������
};

List List:: list_new ()
{
	List a;
	
	return a;
}

void List:: insert (int a)
{
	elem* temp = new elem;
	
	temp->info = a;
	temp->next = head;
	
	head = temp;

	size++;
}

void List:: del ()
{
	elem* temp = head;
	
	head = head->next;
	
	delete temp;

	size--;
}

int List:: search (int a)
{
	elem* temp = head;
	
	int i = 1;
	while ( temp->info != a && temp != NULL ) temp = temp->next, i++;
	
	if ( temp == NULL ) return 0;
	else                return i;
}

void List:: del_pos (int k)
{
	if ( k > size ) return;
	
	if ( k == 1 )
	{
		del();
		return;
	}
	
	elem* p = head;
	for (int i = 1; i < k-1; i++) p = p->next;
	
	elem* temp = p->next;
	p->next = temp->next;
	
	delete temp;
	
	size--;
}

void List:: remove (int a)
{
	int k = search(a);
	while ( k )
	{
		if ( k == 1 ) del();
		else          del_pos(k);
		k = search(a);
	}
}

void List:: list_delete ()
{
	while ( head != NULL ) del();
}

void List:: print ()
{
	elem* p = head;
	
	while ( p != NULL )
	{
		printf("%d ", p->info);
		p = p->next;
	}
}

int main()
{
	List l;
	
   	l.insert(1);
   	l.insert(2);
   	l.insert(3);
   	l.insert(1);
   	l.print();
   	
  	cout << "\n";
   
//	l.remove(1);
//  l.print();
   	
//  cout << "\n";
   	
   	l.list_delete();
   	l.print();
	
	return 0;
}
