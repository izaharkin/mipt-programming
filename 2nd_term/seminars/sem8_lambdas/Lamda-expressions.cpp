/* Lambda-��������� � C++
[] () {} - ������
[] - ������ ���������� ��� ������� �� ���������
() - ������� ���������
{} - ���� �������

struct A 
{
	operator () (...) {}
}; // �������, ��������� ����� ���� �������
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 1 ������
bool cmp (int a, int b)
{
	return a > b;
}

// 2 ������ 
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
	
// [] - ��� �������
// [=] - ��������� ��� ���������� �� �������� (������� ���� ����������� ��������� ����������)
// [&] - ��� ��������� �� ������ (�������� ����������, ������� ��������)
// [x] - ��������� ���������� x �� ��������
// [x, &y] - � �� ��������, � �� ������
// [=, &x, &y] - �� ��������, ����� x � y - ��� �� ������
// [&, x] - ��� �� ������, x - �� ��������
/*
	�������� ������-���������:
1). [capture] (params) -> type {body}
2). [capture] (params) {body}
3). [capture] {body}

*/
	int a = 10;
	
	auto f = [=] () {
		a += 15;
	};
	
	f(); // ������ ������ �����-���������
	
	return 0;
}
