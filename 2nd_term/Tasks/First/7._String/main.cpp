#include "MyString.h"

// There are some problems with "operator+" in this project, I can fix it later
int main()
{
	// constructors
	char *s = "abc";
	mstring ms, ms1("abc");

	// input/output
	cin >> ms; // here works append() too
	cout << ms << '\n';

	cout << ms1 << '\n';

	// mtring(std::string)
	std::string a = "C++ string";
	mstring b(a);
	cout << b << '\n';

	// pop_back()
	ms.pop_back();
	cout << ms << '\n';

	// insert(int, char)
	ms.insert(1, 'g');
	cout << ms << '\n';

	system("PAUSE");

	return 0;
}