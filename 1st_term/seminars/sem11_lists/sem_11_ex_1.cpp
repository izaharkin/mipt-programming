#include "list_tester.h"

using namespace std;

int main()
{
	ListTester:: run("test push front", ListTester:: test_push_front);
	ListTester:: run("test push back", ListTester:: test_push_back);
	ListTester:: run("test new list", ListTester:: test_new_list);
	
	return 0;
}
