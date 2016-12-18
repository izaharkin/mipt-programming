#include <iostream>

using namespace std;

template <class T, class Allocator = std::allocator <T> >
class GreedyVector
{
private:
	T* begin;
	T* end;   // allocate_end too
	allocator my_alloc;
public:
	GreedyVector(): begin(NULL), end(NULL) {}
	GreedyVector(T* _begin, T* _end): begin(_begin), end(_end) {}
	GreedyVector(const GreedyVector& gv): begin(gv.begin), end(gv.end) {}
	
	void push_back(T &);
};

template <class T>
void GreedyVector::push_back(T& x)
{
	void *p = my_alloc.allocate(begin - end + 1);
	
	for (T* i = begin; i != end; i += sizeof(T))
	{
		T* t;
		t = new (p) T(*i);			
	}
	
	my_alloc.deallocate(begin);
	
	begin = p;
	end = end + sizeof(T);
}

int main()
{
	GreedyVector <int> gv;
	vector <int> v;
	
	for (int i = 0; i < 1000000; ++i)
		gv.push_back(i);
	
	for (int i = 0; i < 1000000; ++i)
		v.push_back(i);
// и посотреть vector<>::capacity()
	return 0;
}
