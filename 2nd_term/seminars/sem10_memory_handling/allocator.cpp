/*
Fast Allocator (Fixed Allocator)

1). Выделяем объекты фиксированного размера;
2). С метаинформацией с размеров sizeof(void *) - указатель на следующий блок памяти, выделенный этим аллокатором;

- void Push(TNode *);
- TNode* Pop();

class TNode 
{
	TNode *next;
	char Data[N];
};

Это быстрый, но не оптимальный аллокатор

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
