#include <iostream>
#include <cstdio>

using namespace std;
// ������� (����) ������
struct elem
{
	int info;    // ���������� ��������
	
	elem* prev;  // ������ �� ���������� ������� ������
	elem* next;	 // ������ �� ��������� ������� ������
};

class DList              // ����� - ���������� ������
{
private:
	elem* head;
	elem* tail;
	int size;
	
public:
	DList();             // �����������
	DList(const DList&); // ����������� �����������
	~DList();            // ����������
	
	void AddFirst  (int);       // �������� � ������ ������
	void AddLast   (int);       // �������� � ����� ������
	
	void Insert (const int&, const int&);   // �������� ������� �� ��������� �������
	
	void DelFirst ();     // ������� ������ ������� ������
	void DelLast  ();     // ������� ��������� ������� ������
	void DelPos   (int);  // ������� ������� ������ � �������� �������
	void DelVal   (int);  // ������� ������� ������ � �������� ���������
	void DelAll   ();     // ������� ���� ������
	
	void Print ();        // ������� ��� �������� ������
	void Print (int);     // ������� ������� ��� �������� �������
	
	int Search    (int);  // ����� ������� � ������� ��������� (������ ���������)
	
	elem* GetFirst ();    // ���������� ������ ������� ������
	elem* GetElem  (int); // ���������� ������� ������ � �������� �������
	elem* GetLast  ();    // ���������� ��������� ������� ������
	
	int Size ();   // ���������� ������� ������ ������
	
	void Sort ();  // ���������� ������
	
	DList& operator = (const DList&);  // ������������ ������ ������ �������
	DList  operator + (const DList&);  // ������� �������
	
	// ��������� ���������
   	bool operator == (const DList&);
   	bool operator != (const DList&);
   	bool operator <= (const DList&);
   	bool operator >= (const DList&);
   	bool operator <  (const DList&);
   	bool operator >  (const DList&);

   	DList operator - ();   // ��������������� ������
};
// �����������
DList:: DList ()
{
	head = tail = NULL;
	size = 0;
}
// ����������� �����������
DList:: DList (const DList& L)
{
   head = tail = NULL;
   size = 0;

   elem* temp = L.head;

   while ( temp != NULL )
   {
      AddLast(temp->info);
      
      temp = temp->next;
   }
}
// �������� � ������
void DList:: AddFirst (int x)
{
	elem* temp = new elem;
	
	temp->info = x;
	temp->next = head;
	temp->prev = NULL;
	
	if ( head != NULL ) 
	{
		head->prev = temp;
		head = temp;
	}
	else head = tail = temp;
	
	size++;
}
// �������� � �����
void DList:: AddLast (int x)
{
	elem *temp = new elem;
	
	temp->info = x;
	temp->next = NULL;
	temp->prev = tail;
	
	if ( head != NULL )
	{
		tail->next = temp;
		tail = temp;	
	}
	else head = tail = temp;
	
	size++;
}
// ������� �������� � k-�� �������
void DList:: Insert (const int& x, const int& k)
{
   	if ( k == 1 )
   	{
      	AddFirst(x);
      	return;
   	}
   	
   	if ( k > size )
   	{
      	AddLast(x);
      	return;
   	}

   	elem* p = head;
   	
   	for (int i = 1; i < k-1; i++) p = p->next;
   	
   	elem* temp = new elem;
   	temp->info = x;
   	
   	temp->next = p->next;
   	temp->prev = p;
   	p->next->prev = temp;
	p->next = temp;	

   	size++;
}
// ������� ����� ������ ������� ������
void DList:: DelFirst ()
{
	if ( size == 0 ) return;
	
	elem* temp = head;
	
	head = head->next;
	
	delete temp;
	
	size--;
}
// ������� ����� ��������� ������� ������
void DList:: DelLast()
{
	if ( size == 0 ) return;
	
	elem *temp;

	temp = tail;
	tail = tail->prev;
	if ( size > 1 ) tail->next = NULL;
	
	delete temp;
	
	size--;
}
// ����� ������� � �������� ��������� � ������� ��� ����� �� ������� ��� ����
int DList:: Search (int x)
{
	elem* temp = head;
	
	int i = 1;
	while ( temp->info != x && temp != NULL ) temp = temp->next, i++;
	
	if ( temp == NULL ) return 0;
	else                return i;
}
// ������� �������, ������� ����� � k-�� �������
void DList:: DelPos (int k)
{
	if ( k > size ) return;
	
	if ( k == 1 )
	{
		DelFirst();
		return;
	}
	
	elem* p = head;
	for (int i = 1; i < k-1; i++) p = p->next;
	
	elem* temp = p->next;
	p->next = temp->next;
	temp->next->prev = p;
	
	delete temp;
	
	size--;
}
// ������� ������� � ��������� ���������
void DList:: DelVal (int x)
{
	elem* p = head;
	
	int f = Search(x);
	
	if 	( f )
	{
		if ( f == 1 ) DelFirst();
		else          DelPos(f);
	}
}
// ������� ��� �������� ������ (�� ������)
void DList:: DelAll ()
{
	while ( head != NULL ) DelFirst();
}
// ������� ������ (���������� ���������) �������� ������
int DList:: Size ()
{
	return size;
}
// ������� ��� �������� �������� ������
void DList:: Print ()
{
	elem* p = head;
	
	while ( p != NULL )
	{
		printf("%d ", p->info);
		p = p->next;
	}
	printf("\n");
}
// ������� k-�� ������� ������
void DList:: Print (int k)
{
	elem* p = head;
	
	for (int i = 1; i < k; i++, p = p->next);
	
	printf("%d ", p->info);
}
// ���������� ������ ������� ������
elem* DList:: GetFirst ()
{
	return head;
}
// ���������� ��������� �� k-�� ������� ������
elem* DList:: GetElem (int k)
{
	elem* p = head;
	
	for (int i = 1; i < k; i++) p = p->next;
	
	return p;
}
// ���������� ��������� ������� ������
elem* DList:: GetLast ()
{
	return tail;
}
// ����������
DList:: ~DList ()
{
	DelAll();
}
// �������� ������������ ��� �������
DList& DList:: operator = (const DList& L)
{
    // �������� ������������ �������� "������ ����"
    if ( this == &L ) return *this;

   // �������� ������� ������
   this->~DList(); // DelAll();

   elem* temp = L.head;

   // �������� ��������
   while ( temp != NULL )
   {
      AddLast(temp->info);
      
      temp = temp->next;
   }

   return *this;
}
// �������� (�������) ���� �������
DList DList::operator + (const DList& L)
{
   // ������� �� ��������� ������ �������� ������� ������
   DList res(*this);
	
   elem* temp = L.head;

   // ��������� �� ��������� ������ �������� ������� ������
   while ( temp != NULL )
   {
      res.AddLast(temp->info);
      
      temp = temp->next;
   }

   return res;
}

// ��������� ��������� ���� �������

bool DList:: operator == (const DList& L)
{
   	// ��������� �� ����������
   	if ( size != L.size ) return false;

   	elem *t1, *t2;

   	t1 = head;
   	t2 = L.head;

   	// ��������� �� ����������
   	while ( t1 != tail )
   	{
      	if( t1->info != t2->info ) return false;
		
      	t1 = t1->next;
      	t2 = t2->next;
  	}

   	return true;
}

bool DList:: operator != (const DList& L)
{
   	return !( *this == L );
}

bool DList:: operator >= (const DList& L)
{
    return (( size > L.size || *this == L ) ? true : false);
}

bool DList:: operator <= (const DList& L)
{
   	return (( size < L.size || *this == L ) ? true : false); 
}

bool DList:: operator > (const DList& L)
{
   	return ( size > L.size ? true : false );
}

bool DList:: operator < (const DList& L)
{
   	return ( size < L.size ? true : false );
}

// �������� ���������� ������
DList DList:: operator - ()
{
   DList res;
   
   elem* temp = head;
   
   while ( temp != NULL )
   {
       res.AddFirst(temp->info);
       
       temp = temp->next;
   }

   return res;
}

int main()
{
	DList L;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int x;
	while ( cin >> x )
		L.AddFirst(x);	   	
   
	while ( L.Size() )
	{
		cout << L.GetFirst() << "\n";
		L.DelFirst();
	}
   
   	return 0;
}
