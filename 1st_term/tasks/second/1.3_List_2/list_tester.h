#include "list.h"

using namespace std;

class ListTester
{
private:
	static const int n = 10;
	static bool check_length (const List<int>&, const int);
public:
	static bool test_new_list   ();
	
	static bool test_pop_front  ();
	static bool test_push_front ();
	static bool test_pop_back   ();
	static bool test_push_back  ();
	
	static bool test_reverse    ();
	static bool mem_leak        ();
	
	static void run (const string& name, bool (*test) (void));
};
