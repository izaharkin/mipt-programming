#include <iostream>

using namespace std;

f (const string& s)
{
	const_cast <string&> (s).method_that_changes_s();
}

int main()
{
	T1* t;
	T2* t2 = static_cast <T2*> (t); // приведение типа на этапе компил€ции, статическое
	
	T2* t2 = dynamic_cast <T2*> (t); // приведение типа на этапе компил€ции, динамическое, 
								     // он выдаст NULL, если не получилось привести
								     // с помощью него монжо пон€ть, приводитс€ базовый класс к производному или нет
	T2* t2 = reinterpret_cast  <T2*> (t); // абсолютное зло
	
	T2 t2 = const_cast <T2> (t); // снимает константность с объекта
	
	return 0;
}
