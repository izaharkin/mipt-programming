/* Lambda-выражения в C++
[] () {} - лямбды
[] - список переменных для захвата ищ контекста
() - входные параметры
{} - тело функции

struct A 
{
	operator () (...) {}
}; // функтор, объектами могут быть функции
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 1 способ
bool cmp (int a, int b)
{
	return a > b;
}

// 2 способ 
struct Comparator
{
	bool operator () (int l, int r) {
		return l > r;
	}	
};

int main()
{
	[](int left, int right) {
		return left < right;
	};
	
	vector <int> v(10, 10);
	
//	sort(v.negin(), v,end(), Comparator());
	sort(v.begin(), v.end(), 
		[](int left, int right) {
			return left < right;
	});	
	
// [] - без захвата
// [=] - захватить все переменные по значению (изменит свои собственные локальные переменные)
// [&] - все перменные по ссылке (пизменит переменные, которые захватит)
// [x] - захватить переменную x по значению
// [x, &y] - х по значению, у по ссылке
// [=, &x, &y] - по значению, кроме x и y - они по ссылке
// [&, x] - все по ссылке, x - по значению
/*
	Описание лямбда-выражений:
1). [capture] (params) -> type {body}
2). [capture] (params) {body}
3). [capture] {body}

*/
	int a = 10;
	
	auto f = [=] () {
		a += 15;
	};
	
	f(); // пример вызова лямба-выражения
	
	return 0;
}
