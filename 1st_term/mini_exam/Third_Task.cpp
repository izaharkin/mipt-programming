#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int n = 100;

template <class T>
struct elem
{
	T info;
	elem<T> *next;

	elem (T x, elem<T> *el) : info( x ), next( el ) {}
};

template <class T>
class Queue
{
private:
	elem<T> *head;
	elem<T> *tail;
	
	int size;
public:
	Queue  ();  // �����������
	~Queue ();  // ����������
	
	void Push (T);  // �������� ������� � ����� ������� ("���������")
	T  Pop  ();     // ������� (������� � ������� ��������) ������� �� ������ ������� ("����������")
	
	bool IsFull  ();  // �������� �� ������� �������
	bool IsEmpty ();  // �������� �� ������� �������
	int  Size    ();  // ���������� ������� ������ (���������� ���������) �������
	
	int GetFirst ();  // ������� (��� ��������) ������ ������� �������
	int GetLast  ();  // ������� (��� ��������) ��������� ������� �������
	
	void Clear ();    // �������� ������� (������� ��� �������s �� ������)
};

template <class T>
Queue<T>:: Queue ()
{
	head = tail = NULL;
	size = 0;
}

template <class T>
Queue <T>:: ~Queue ()
{
	Clear();	
}

template <class T>
void Queue <T>:: Clear ()
{
	while ( head != NULL )
	{
		elem<T> *temp = head;
		
		head = head->next;
		
		delete temp;
	}
	
	size = 0;
}

template <class T>
void Queue <T>:: Push (T x)
{
	elem<T> *temp = new elem<int>(x, NULL);
	
	if ( head != NULL )
	{
		tail->next = temp;
		tail = temp;
	}
	else head = tail = temp;
	
	size++;
}

template <class T>
T Queue<T>:: Pop ()
{
	elem<int> *temp = head;
	T x = temp->info;
	
	head = head->next;
	
	delete temp;
	size--;
	
	return x;
}

template <class T>
bool Queue<T>:: IsFull ()
{
	return size >= n;
}

template <class T>
bool Queue<T>:: IsEmpty ()
{
	return size == 0;
}

template <class T>
int Queue<T>:: Size ()
{
	return size;
}

template <class T>
int Queue<T>:: GetFirst ()
{
	return head->info;
}

template <class T>
int Queue<T>:: GetLast ()
{
	return tail->info;
}

int main()
{
	Queue <int> q;
	string s;
	
	cin >> s;
	while ( s != "exit" )
	{
		if ( s == "push" )
		{
			int x;
			cin >> x;
			q.Push(x);
			cout << "ok\n";
		}
	
		if ( s ==  "pop" ) 
		{
			if ( q.Size() != 0 ) cout << q.Pop() << "\n";
			else                 cout << "error\n";
		}
			
		if ( s == "front" ) 
		{
			if ( q.Size() != 0 ) cout << q.GetFirst() << "\n";
			else                 cout << "error\n";
		}
			
		if ( s == "size" ) cout << q.Size() << "\n";
			
		if ( s == "clear" )
		{
			q.Clear();
			cout << "ok\n";
		}
		
		cin >> s;
	}
	
	cout << "bye";
	
	return 0;
}
