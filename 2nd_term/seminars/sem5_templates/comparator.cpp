#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
	Point(): x(0), y(0) {}
	Point (int _x, int _y): x(_x), y(_y) {}
	bool operator < (const Point& b) const
	{
		if ( x == b.x )
			return y < b.y;
		return x < b.x;
	}
};

template <class T>
class Comp
{
public:
	static int count;
	bool operator () (T a, T b)
	{
		count++;
		return a < b;	
	}
};

template <class T> int Comp <T>::count = 0;

int main()
{
	vector <Point> vec;
	vec.resize(100);
	
	for (int i = 0; i < 100; ++i)
		vec[i] = Point(i, 2*i);
	
	sort(vec.begin(), vec.end(), Comp <Point> ());
	
	cout << Comp <Point>::count << "\n";
/////////////////////////////////////////////////////////////////////////////////////	
	vec.resize(1000);
	
	for (int i = 0; i < 1000; ++i)
		vec[i] = Point(i, 2*i);
		
	sort(vec.begin(), vec.end(), Comp <Point> ());
	
	cout << Comp <Point>::count;
	
	return 0;
}
