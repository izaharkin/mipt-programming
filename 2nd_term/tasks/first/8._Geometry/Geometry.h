#ifndef __GEOMETRY_H__

#define __GEOMETRY_H__

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.1415926535
#endif

#define eps 1e-9

using namespace std;

struct point
{
	double x;
	double y;
	point(): x(0), y(0) {}
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (const point& p) const;
	friend ostream& operator << (ostream& o, const point& p);
};

double dest(const point &, const point &);
double det(const point&, const point&);
int signum(double d);
inline bool intersect_1d(double, double, double, double);

struct segment
{
	point a;
	point b;
	double d;
	segment() : a(point(0, 0)), b(point(0, 0)), d(0) {}
	segment(const segment & _seg) : a(_seg.a), b(_seg.b), d(_seg.d) {}
	segment(const point& _a, const point& _b) : a(_a), b(_b), d(dest(a, b)) {}

	bool point_in_box(const point&) const;
};

double scalar(const segment&, const segment&);

struct line
{
	double A;
	double B;
	double C;
	line() : A(0), B(0), C(0) {}
	line(const segment& seg)
	{
		A = seg.b.y - seg.a.y;
		B = seg.a.x - seg.b.x;
		C = -A * seg.a.x - B * seg.a.y;
	}
	line(const point& a, const point& b)
	{
		A = b.y - a.y;
		B = a.x - b.x;
		C = -A * a.x - B * a.y;
	}

	int sign(const point&) const;
	double dist(const point& p) const;
};

class Shape
{
protected:
	vector <point> p;
public:
	Shape(): p(0) {}
	Shape(vector <point>& _p)
	{
		for (size_t i = 0; i < _p.size(); ++i)
			p.push_back(_p[i]);
	}

	virtual double area() const = 0;
	virtual bool boundary(const point &) const = 0;
	virtual bool is_in(const point &) const = 0;
	virtual bool intersect(const segment &, point&, point&) const = 0;
};

class Circle: public Shape
{
protected:
	double r;
	point c;
public:
	Circle() : Shape(), r(0), c(point(0, 0)) {}
	Circle(point _c, double _r) : Shape(), r(_r), c(_c) {}

	double area() const;
	bool boundary(const point &) const;
	bool is_in(const point &) const;
	bool intersect(const segment &, point&, point&) const;
};

class Polygon: public Shape
{
protected:
	int q;
public:
	Polygon() : Shape(), q(0) {}
	Polygon(vector <point>& _p) : Shape(_p), q(_p.size())
	{
		if (q < 3)
		{
			cerr << "Wrong number of points, that`s not a polygon!";
			p.resize(0);
			q = 0;
			return;
		}
	}

	double area() const;
	bool boundary(const point &) const;
	bool is_in(const point &) const;
	bool intersect(const segment &, point&, point&) const;
};

class Triangle: public Polygon
{
protected:
	segment a;
	segment b;
	segment c;
public:
	Triangle() : Polygon(), a(), b(), c() {}
	Triangle(vector <point> &_p) : Polygon(_p)
	{
		if (q != 3)
		{
			cerr << "Wrong number of points, that`s not a triangle!\n";
			p.resize(0);
			q = 0;
			return;
		}
		a = segment(p[0], p[1]);
		b = segment(p[1], p[2]);
		c = segment(p[2], p[0]);
	}
	
	double area() const;
	bool boundary(const point &) const;
	bool is_in(const point &) const;
	bool intersect(const segment &, point&, point&) const;
};

class Square: public Polygon
{
protected:
	segment a;
public:
	Square() : Polygon() {}
	Square(vector <point> &_p) : Polygon(_p)
	{
		if (q != 4)
		{
			cerr << "Wrong number of points, that`s not a square!\n";
			p.resize(0);
			q = 0;
			a = segment();
			return;
		}
		segment cur, prev;
		cur = segment(p[0], p[1]);
		for (int i = 1; i < q; ++i)
		{
			int j = (i + 1) % q;
			prev = cur;
			cur = segment(p[i], p[j]);	
			if (cur.d != prev.d || scalar(cur, prev) != 0)
			{
				cerr << "Wrong points, that`s not a square!\n";
				p.resize(0);
				q = 0;
				a = segment();
				return;
			}
		}
		a = segment(p[0], p[1]);
	}

	double area() const;
	bool boundary(const point &) const;
	bool is_in(const point &) const;
	bool intersect(const segment &, point&, point&) const;
};

class Rectangle: public Polygon
{
protected:
	segment a;
	segment b;
public:
	Rectangle() : Polygon() {}
	Rectangle(vector <point> &_p) : Polygon(_p)
	{
		if (q != 4)
		{
			cerr << "Wrong number of points, that`s not a rectangle!\n";
			p.resize(0);
			q = 0;
			a = segment();
			b = segment();
			return;
		}

		segment cur, prev;
		cur = segment(p[0], p[1]);
		for (int i = 1; i < q; ++i)
		{
			int j = (i + 1) % q;
			prev = cur;
			cur = segment(p[i], p[j]);
			if (scalar(cur, prev) != 0)
			{
				cerr << "Wrong points, that`s not a rectangle!\n";
				p.resize(0);
				q = 0;
				a = segment();
				b = segment();
				return;
			}
		}
		a = segment(p[0], p[1]);
		b = segment(p[1], p[2]);
	}

	double area() const;
	bool boundary(const point &) const;
	bool is_in(const point &) const;
	bool intersect(const segment &, point&, point&) const;
};

class Convex: public Polygon
{
public:
	Convex() : Polygon() {}
	Convex(vector <point> &_p) : Polygon(_p)
	{
		segment prev, cur, next;
		prev = segment(p[0], p[1]);
		cur = segment(p[1], p[2]);
		for (int i = 2; i < q; ++i)
		{
			int j = (i + 1) % q;
			next = segment(p[i], p[j]);
			if (signum(det(point(prev.b.x - prev.a.x, prev.b.y - prev.a.y), point(cur.b.x - cur.a.x, cur.b.y - cur.a.y))) !=
				signum(det(point(cur.b.x - cur.a.x, cur.b.y - cur.a.y), point(next.b.x - next.a.x, next.b.y - next.a.y))))
			{
				cerr << "It is not a convex polygon!\n";
				p.resize(0);
				q = 0;
				return;
			}
		}
		prev = cur;
		cur = next;
	}

	double area() const;
	bool boundary(const point &) const;
	bool is_in(const point &) const;
	bool intersect(const segment &, point&, point&) const;
};

#endif /*__GEOMETRY_H__*/