#include <iostream>
#include <vector>

// using namespace std; - часто эта строчка запрещена

// .h - объявления
// .cpp - реализация
// #pragma once - директива препроцессора, вместо #ifndef *** .. #define *** .. #endif

// Конструкторы
vector::vector (size_t n)
{
	...;
}

vector::vector (size_t n, const T val)
{
	...;
}

vector::vector (it1, it2)
{
	...;
}

int main()
{
	std::vector <int> v;
	
	for (/*typename*/ std::vector <int>::iterator it = v.begin(); it != v.begin(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	// const_ iterator - если итератор на константный объект
	
	// Бонус C++11
	// auto - тип данных, который сам подстраивается под наш
	for (auto it = v.begin(); it != v.begin(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	
	// Методы vector<>
	v.begin();  // итератор на начало
	v.end();    // итератор на элемент за последним
	v.rbegin(); // итератор на последний
	v.rend();   // итератор на элемент до первого
	
	v.size();   // размер
	v.empty();  // пустой или нет
	
	v.front();  // вернуть первый элемент
	v.back();   // вернуть последний элемент 
	
	/* !!! Никогда не вычитать из беззнаковых типов !!! */
	
	v.push_back(); // добавить элемент в конец
	v.pop_back();  // удалить последний
	
	v.insert(iterator it, T val);  // добавить элемент со значением val в место it
	v.erase(iterator beg, iterator end); // удалить интервал от beg до end
	
	return 0;
}
