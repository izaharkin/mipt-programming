#include "Geometry.h"

ostream& operator << (ostream& o, const point& p)
{
	o << p.x << ' ' << p.y;
	return o;
}

bool point::operator < (const point& p) const 
{
	return x < p.x - eps || fabs(x - p.x) < eps && y < p.y - eps;
}

double dest(const point& a, const point& b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double det(const point& a, const point& b)
{
	return (a.x * b.y - a.y * b.x);
}

int signum(double d)
{
	return (d > 0 ? 1 : (d < 0 ? -1 : 0));
}

double scalar(const segment& seg1, const segment& seg2)
{
	return (fabs(seg1.b.x - seg1.a.x) * fabs(seg2.b.x - seg2.a.x) + fabs(seg1.b.y - seg1.a.y) * fabs(seg2.b.y - seg2.a.y));
}

inline bool inter(double a, double b, double c, double d) 
{
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return max(a, c) <= min(b, d) + eps;
}

bool segment::point_in_box(const point& p) const

{
	return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
		   min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

int line::sign(const point& p) const
{
	double t = A * p.x + B * p.y + C;
	return (t > 0 ? 1 : (t < 0 ? -1 : 0));
}

double line::dist(const point& p) const 
{
	return (A * p.x + B * p.y + C / sqrt(A*A + B*B));
}

double Circle::area() const
{
	return M_PI * r * r;
}

bool Circle::boundary(const point& p) const
{
	return (r == dest(c, p));
}

bool Circle::is_in(const point& p) const
{
	return (r > dest(c, p));
}

bool Circle::intersect(const segment& seg, point& p1, point& p2) const
{
	line l(seg);
	l.C += l.A * c.x + l.B * c.y;

	double x0 = -l.A * l.C / (l.A * l.A + l.B * l.B);
	double y0 = -l.B * l.C / (l.A * l.A + l.B * l.B);

	if (l.C * l.C > r * r * (l.A * l.A + l.B * l.B) + eps)
		return false;
	else if (fabs(l.C * l.C - r * r * (l.A * l.A + l.B * l.B)) < eps)
	{
		if (seg.point_in_box(point(x0, y0)))
		{
			p1 = p2 = point(x0, y0);
			return true;
		}
	}
	else 
	{
		double d = r * r - l.C * l.C / (l.A * l.A + l.B * l.B);
		double mult = sqrt(d / (l.A * l.A + l.B * l.B));
		double ax, ay, bx, by;
		ax = x0 + l.B * mult;
		bx = x0 - l.B * mult;
		ay = y0 - l.A * mult;
		by = y0 + l.A * mult;
		if (seg.point_in_box(point(ax, ay)) && seg.point_in_box(point(bx, by)))
		{
			p1 = point(ax, ay);
			p2 = point(bx, by);
			return true;
		}
	}

	return false;
}

double Polygon::area() const
{
	double s = 0;
	for (int i = 0; i < q; ++i)
	{
		int j = (i + 1) % q;
		s += det(p[i], p[j]) / 2.0;
	}
	return fabs(s);
}

bool Polygon::boundary(const point& x) const
{
	for (int i = 0; i < q; ++i)
	{
		int j = (i + 1) % q;
		segment seg(p[i], p[j]);
		line l(p[i], p[j]);
		if (l.sign(x) == 0)
			if (seg.point_in_box(x))
				return true;
	}
	return false;
}

bool Polygon::is_in(const point& x) const
{
	if (boundary(x))
		return false;

	int cur_sign, prev_sign;
	for (int i = 0; i < q; ++i)
	{
		int j = (i + 1) % q;
		line l(p[i], p[j]);

		cur_sign = l.sign(x);
		if (i == 0)            // crutch, I`m sorry
			prev_sign = cur_sign;
		if (cur_sign != prev_sign)
			return false;

		prev_sign = cur_sign;
	}

	return true;
}

bool Polygon::intersect(const segment& seg, point& l, point& r) const
{
	point c = seg.a;
	point d = seg.b;
	for (int i = 0; i < q; ++i)
	{
		int j = (i + 1) % q;
		point a(p[i]);
		point b(p[j]);

		if (!inter(a.x, b.x, c.x, d.x) || !inter(a.y, b.y, c.y, d.y))
			return false;

		line m(a, b);
		line n(c, d);
		double zn = det(point(m.A, m.B), point(n.A, n.B));
		if (abs(zn) < eps) 
		{
			if (abs(m.dist(c)) > eps || abs(n.dist(a)) > eps)
				return false;
			if (b < a) swap(a, b);
			if (d < c) swap(c, d);
			l = max(a, c);
			r = min(b, d);
			return true;
		}
		else 
		{
			l.x = r.x = -det(point(m.C, m.B), point(n.C, n.B)) / zn;
			l.y = r.y = -det(point(m.A, m.C), point(n.A, n.C)) / zn;
			segment seg1(a, b);
			segment seg2(c, d);
			return seg1.point_in_box(l) && seg2.point_in_box(r);
		}
	}
}

double Triangle::area() const
{
	return Polygon::area();
}

bool Triangle::boundary(const point & x) const
{
	return Polygon::boundary(x);
}

bool Triangle::is_in(const point & x) const
{
	return Polygon::is_in(x);
}

bool Triangle::intersect(const segment& seg, point& l, point& r) const
{
	return Polygon::intersect(seg, l, r);
}

double Square::area() const
{
	return a.d * a.d;
}

bool Square::boundary(const point& x) const
{
	return Polygon::boundary(x);
}

bool Square::is_in(const point& x) const
{
	return Polygon::is_in(x);
}

bool Square::intersect(const segment& seg, point& l, point& r) const
{
	return Polygon::intersect(seg, l, r);
}

double Rectangle::area() const
{
	return a.d * b.d;
}

bool Rectangle::boundary(const point& x) const
{
	return Polygon::boundary(x);
}

bool Rectangle::is_in(const point& x) const
{
	return Polygon::is_in(x);
}

bool Rectangle::intersect(const segment& seg, point& l, point& r) const
{
	return Polygon::intersect(seg, l, r);
}

double Convex::area() const
{
	return Polygon::area();
}

bool Convex::boundary(const point& x) const
{
	return Polygon::boundary(x);
}

bool Convex::is_in(const point& x) const
{
	return Polygon::is_in(x);
}

bool Convex::intersect(const segment& seg, point& l, point& r) const
{
	return Polygon::intersect(seg, l, r);
}
