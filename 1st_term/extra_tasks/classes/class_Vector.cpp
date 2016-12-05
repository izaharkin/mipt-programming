#include <iostream>
#include <cstdlib>
//#include "My_Vector"

using namespace std;

template <class T>
class Vector
{
private:
	T* a;
	int sz;
public:
	//  ŒÕ—“–” “Œ–€
	Vector () { a = NULL; sz = 0; }
	
	Vector (const int& size)
	{
		sz = size;
		a = new T[sz];
	}
	
	Vector (const int& size, const T& C)
	{
		sz = size;
		a = new T[size];
		for (int i = 0; i < sz; i++)
			a[i] = C;
	}
	// Ã≈“Œƒ€
	int size ()
	{
		return sz;
	}
	
	void resize (const int& n)
	{
		realloc(a, n*sizeof(T));
	}
	
	void push_back (const T& t)
	{
		sz++;
		
		T* b = new T[sz];
		for (int i = 0; i < sz-1; i++)
			b[i] = a[i];
		b[sz-1] = t;
		
		delete[] a;
		a = new T[sz];
		for (int i = 0; i < sz; i++)
			a[i] = b[i];
			
		delete[] b;
	}
	
	void append (Vector <T>& b)
	{
		T* n = new T[sz + b.size()];
		
		for (int i = 0; i < sz; i++)
			n[i] = a[i];
			
		for (int i = sz; i < sz+b.size()-1; i++)
			n[i] = b[sz-i];
			
		delete[] a;
		a = n;
		
	}
	
	void print ()
	{
		for (int i = 0 ; i < sz; i++)
			cout << a[i] << " ";
	}
	
	void scan ()
	{
		for (int i = 0; i < sz; i++)
			cin >> a[i];
	}
	// Œœ≈–¿“Œ–€
	T operator [] (const int& i)
	{
		return a[i];
	}
	
	bool operator < (const Vector <T>& b)
	{
		return sz < b.sz; 
	}
	
	bool operator > (const Vector <T>& b)
	{
		return sz > b.sz; 
	}
	
	bool operator == (const Vector <T>& b)
	{
		return sz == b.sz;
	}
	/*
	ostream& operator << ()
	{
		for (int i = 0; i < sz; i++)
			cout << a[i] << " ";
	}*/
	// ƒ≈—“–” “Œ–
	~Vector ()
	{
		sz = 0;
		delete[] a;
	}
};

int main()
{
	int n1, n2;
	Vector <int> a, b;
	
	cin >> n1 >> n2;
	
	a.resize(n1);
	a.scan();
	
	/*b.resize(n2);
	b.scan();
		
	a.append(b);
	
	a.print();
	*/
	a.push_back(6);
	
	a.print();
	
	return 0;
}
