// ГЛАВА 12. Пункты 12.1 и 12.3
// ДЕРЕВЬЯ (Двоиные деревья поиска)
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandInt
{
private:
	int left, delta;
public:
	RandInt (int a, int b) : left(a), delta(b-a) {}
	int operator () () const
	{
		return left + delta * (rand() / double(RAND_MAX));	
	}
};

class Bin_Tree
{
public:
	const int key;
	char value;
	
	Bin_Tree (int k, char v = 'w') : key(k), value(v), p(0), left(0), right(0) {}
	
	int depth        ();
	Bin_Tree* find   (int k);
	Bin_Tree* insert (Bin_Tree* n);
	
	
	Bin_Tree* erase (Bin_Tree *n);
	Bin_Tree* trans (Bin_Tree* u, Bin_Tree* v);
	
	Bin_Tree* bt_max (Bin_Tree *x);
	Bin_Tree* bt_min (Bin_Tree *x);
	
	void clear      ();
	
	friend void pre_order_(Bin_Tree *t);
	template <class Func> friend void pre_order  (Bin_Tree* root, Func& fn);
	template <class Func> friend void in_order   (Bin_Tree* root, Func& fn);
	template <class Func> friend void post_order (Bin_Tree* root, Func& fn);
private:
	Bin_Tree *p, *left, *right;
};

class PrintKey
{
public:
	void operator () (Bin_Tree* t)
	{
		cout << t->key << " " << t->value << "\n";
	}
};
