#include "Students.h"

int main()
{
	map <string, int> m1, m2, m3;

	m1.insert(make_pair("Algebra", 6));
	m1.insert(make_pair("English", 0));
	
	m2.insert(make_pair("Algebra", 0));
	m2.insert(make_pair("English", 1));
	
	m3.insert(make_pair("Algebra", 2));
	m3.insert(make_pair("English", 0));
///////////////////////////////////////////////////////////////////
	Student a(m1, "Ilya"), b(m2, "Max"), c(m3, "John");
	Group g;

	g.add(a);
	g.add(b);
	g.add(c);

	vector <string> vec1 = g.getReprovers("Algebra");
	vector <string> vec2 = g.getReprovers("English");
	for (size_t i = 0; i < vec1.size(); ++i)
		cout << vec1[i] << " ";
	cout << "\n";
	for (size_t i = 0; i < vec2.size(); ++i)
		cout << vec2[i] << " ";
	cout << "\n";

	g.popBadStudents(1);
	g.show();
	
	system("PAUSE");

	return 0;
}