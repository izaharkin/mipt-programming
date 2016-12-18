#include <iostream>
#include <vector>

// using namespace std; - ����� ��� ������� ���������

// .h - ����������
// .cpp - ����������
// #pragma once - ��������� �������������, ������ #ifndef *** .. #define *** .. #endif

// ������������
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
	// const_ iterator - ���� �������� �� ����������� ������
	
	// ����� C++11
	// auto - ��� ������, ������� ��� �������������� ��� ���
	for (auto it = v.begin(); it != v.begin(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	
	// ������ vector<>
	v.begin();  // �������� �� ������
	v.end();    // �������� �� ������� �� ���������
	v.rbegin(); // �������� �� ���������
	v.rend();   // �������� �� ������� �� �������
	
	v.size();   // ������
	v.empty();  // ������ ��� ���
	
	v.front();  // ������� ������ �������
	v.back();   // ������� ��������� ������� 
	
	/* !!! ������� �� �������� �� ����������� ����� !!! */
	
	v.push_back(); // �������� ������� � �����
	v.pop_back();  // ������� ���������
	
	v.insert(iterator it, T val);  // �������� ������� �� ��������� val � ����� it
	v.erase(iterator beg, iterator end); // ������� �������� �� beg �� end
	
	return 0;
}
