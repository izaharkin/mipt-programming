/*
Fast Allocator (Fixed Allocator)

1). �������� ������� �������������� �������;
2). � ��������������� � �������� sizeof(void *) - ��������� �� ��������� ���� ������, ���������� ���� �����������;

- void Push(TNode *);
- TNode* Pop();

class TNode 
{
	TNode *next;
	char Data[N];
};

��� �������, �� �� ����������� ���������

-----------------
-*- Allocator -*-
-----------------
map <int, string> m;
// map< int, string, less<int>, allocator< pair<int, string> > > - default

template <class T>
bool less (T& a, T& b);
{
	return a < b;
}

Allocator methods:
- allocate
- deallocate
- construct (new(address) .. - the simplest construct)
- destroy
*/
