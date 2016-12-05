#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
	double x;
	double y;
	
	Point (double x, double y)
	{
		x = x;
		y = y;
	}	
};

double dist (Point a, Point b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

int main()
{
	int n = 4;
	double x, y;
	vector <Point> a;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		a.push_back(Point(x, y));
	}
	
	int k = 0;
	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
			dists[k++] = dist(a[i], a[j]);
	
	sort(dists, dists+n);
	
	cout << dists[2] * dists[4];
	
	return 0;
}
