#include <iostream>

using namespace std;

template <class T>
class smart_ptr
{
private:
	T* ptr;
public:
	smart_ptr() : ptr() {}
	smart_ptr(T* _ptr) : ptr(_ptr) {}
	smart_ptr(const smart_ptr& _sptr) = delete;
	T& operator * () { return *ptr; }
	~smart_ptr() { if ( ptr != NULL ) delete ptr; }
};