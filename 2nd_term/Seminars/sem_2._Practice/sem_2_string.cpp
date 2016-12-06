#include <iostream>
#include <string>

int main ()
{
	string s;
	
	s.find(t, i);  // вернёт индекс первого элемента строки s, после которого содержится подстрока t которую мы искали, начиная с элемента с индексом i
	string:: npos; // максимальный размер строки
	s.rfind();     // последнее вхождение
	
	s.find_first_of(string t);      // первое вхождение любого из элементов t в s (знаки препинания)
	s.find_first_not_of(string t);  // первое НЕвхождение элементов t в s
	
	s.compare(string t); // сравнение
	s.c_str(); // еобразование к строке в стиле С
	
	return 0;
}
