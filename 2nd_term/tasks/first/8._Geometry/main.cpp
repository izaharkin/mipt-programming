#include "Geometry.h"

int main()
{
	Circle circle(point(5, 5), 2);

	cout << circle.area() << '\n';
	cout << circle.boundary(point(5, 7)) << '\n';
	cout << circle.boundary(point(8, 7)) << '\n';
	cout << circle.is_in(point(5, 6)) << '\n';
	cout << circle.is_in(point(5, 8)) << '\n';

	point a(6, 6), b(10, 10), l, r;
	if (circle.intersect(segment(a, b), l, r))
		cout << l << ' ' << r;
////////////////////////////////////////////////////////////////
	vector <point> tri;
	tri.push_back(point(0, 0));
	tri.push_back(point(0, 5));
	tri.push_back(point(5, 5));

	Triangle triangle(tri);

	cout << triangle.area() << '\n';
	cout << triangle.boundary(point(2, 5)) << '\n';
	cout << triangle.boundary(point(10, 10)) << '\n';
	cout << triangle.is_in(point(2, 4)) << '\n';
	cout << triangle.is_in(point(10, 10)) << '\n';

	if (triangle.intersect(segment(a, b), l, r))
		cout << l << ' ' << r;
////////////////////////////////////////////////////////////////
	vector <point> sq;
	sq.push_back(point(0, 0));
	sq.push_back(point(0, 5));
	sq.push_back(point(5, 5));
	sq.push_back(point(5, 0));

	Square square(sq);

	cout << square.area() << '\n';
	cout << square.boundary(point(2, 5)) << '\n';
	cout << square.boundary(point(10, 10)) << '\n';
	cout << square.is_in(point(3, 3)) << '\n';
	cout << square.is_in(point(10, 10)) << '\n';

	if (square.intersect(segment(a, b), l, r))
		cout << l << ' ' << r;
////////////////////////////////////////////////////////////////
	vector <point> rec;
	rec.push_back(point(0, 0));
	rec.push_back(point(0, 5));
	rec.push_back(point(10, 5));
	rec.push_back(point(10, 0));

	Rectangle rectangle(rec);

	cout << rectangle.area() << '\n';
	cout << rectangle.boundary(point(5, 5)) << '\n';
	cout << rectangle.boundary(point(100, 100)) << '\n';
	cout << rectangle.is_in(point(3, 3)) << '\n';
	cout << rectangle.is_in(point(100, 100)) << '\n';

	if (rectangle.intersect(segment(a, b), l, r))
		cout << l << ' ' << r;
////////////////////////////////////////////////////////////////
	vector <point> con;
	con.push_back(point(0, 0));
	con.push_back(point(0, 5));
	con.push_back(point(10, 5));
	con.push_back(point(12, 4));
	con.push_back(point(10, 0));

	Convex convex(con);

	cout << convex.area() << '\n';
	cout << convex.boundary(point(5, 5)) << '\n';
	cout << convex.boundary(point(100, 100)) << '\n';
	cout << convex.is_in(point(3, 3)) << '\n';
	cout << convex.is_in(point(100, 100)) << '\n';

	if (convex.intersect(segment(a, b), l, r))
		cout << l << ' ' << r << '\n';

	system("PAUSE");

	return 0;
}