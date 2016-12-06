#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(const int _x, const int _y): x(_x), y(_y) {}	
	Point(const Point& _p): x(_p.x), y(_p.y) {}
};

bool operator != (const Point& a, const Point& b)
{
    return !(a.x == b.x && a.y == b.y);
}

struct Edge
{
	Point a;
	Point b;
	Edge(): a(), b() {}
	Edge(const Point& _a, const Point& _b): a(_a), b(_b) {}
	Edge(const Edge& _e): a(_e.a), b(_e.b) {}
};
// oriented triangle square
int orientTriangle (const Point& p1, const Point& p2, const Point& p3)
{
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

bool point_in_box (const Point& p1, const Point& p, const Point& p2)
{
    return ( p1.x <= p.x && p.x <= p2.x &&
             p1.y <= p.y && p.y <= p2.y );
}
// destination between points
double dest(const Point& a, const Point& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dest(const Edge& A, const Point& b)
{
	double S = orientTriangle(A.a, b, A.b);
	return 2 * S / (.0 + dest(A.a, A.b));
}
// Jarvis convex hull search algorithm
vector<int> jarvis(const vector<Point>& a)
{
	vector <int> convex_hull;
	size_t n = a.size();
    int base = 0;
    // base - index of the leftest and lowest point
    for (int i = 1; i < n; i++)
    {
        if ( a[i].y < a[base].y )
            base = i;
        else
            if (a[i].y == a[base].y &&
                a[i].x <  a[base].x)
            base = i;
    }

    convex_hull.push_back(base); 
 
    int first = base;
    int cur = base;
    do
    {
        int next = (cur + 1) % n;
        
        for (size_t i = 0; i < n; i++)
        {
            int sign = orientTriangle(a[cur], a[next], a[i]);

            if ( sign < 0 ) 
				next = i;
            else if ( sign == 0 )
            {
                if ( point_in_box(a[cur], a[next], a[i]) )
                    next = i;
            }
        }
        
        cur = next;
        convex_hull.push_back(next);
    }
    while ( cur != first );
    
    return convex_hull;
}

int main()
{
	int n;
	vector <Point> people;
	
	cin >> n;
	for (size_t i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		people.push_back(Point(x, y));
	}
	// vector of indexes of points from people that are in convex_hull (counter-clockwise)
	vector <int> convex_hull = jarvis(people);

	for (size_t i = 0; i < convex_hull.size(); ++i)
		cout << convex_hull[i] << " ";
	cout << "\n";
/*	
 	Установить A на первое ребро
 	Установить B на самую удаленную от A вершину
 	answer := distanceEdgeVertex(A, B)
 	for i := 1 to n - 1 do 
 		A := nextEdge(A)  // Переходим на следующее ребро в порядке обхода
 		while distanceEdgeVertex(A, B) < distanceEdgeVertex(A, next(B)) do
 			B := next(B)
 		answer := max(answer, distanceVertexVertex(begin(A), B))
 		answer := max(answer, distanceVertexVertex(end(A), B))
	return answer
*/
	Edge A = Edge(people[convex_hull[0]], people[convex_hull[1]]); // first edge
	Point b;                                                       // the farthest point from edge 'a'
	double M = 0; // strater destination
	int ind_b;    // current max index
	Edge ans;     // pair of points - answer
	for (size_t i = 2; i < convex_hull.size(); ++i)
	{
		Point p = people[convex_hull[i]];
		if ( dest(A, p) > M )
		{
			b = p;
			ind_b = i;
			M = dest(A, p);
		}
	}
	double d = M;
	for (size_t i = 1; i < n; ++i)
	{
		A.a = people[convex_hull[i]];
		A.b = people[convex_hull[(i + 1) % n]];
		while ( dest(A, b) < dest(A, people[convex_hull[(ind_b + 1) % n]]) )
		{
			b = people[convex_hull[(ind_b + 1) % n]];
			ind_b = (ind_b + 1) % n;
		}
		ans.a = b;
		double d1 = max(d, dest(A.a, b));
		double d2 = max(d, dest(A.b, b));
		ans.b = (d1 > d2 ? A.a : A.b);
	}
	
	cout << ans.a << ' ' << ans.b;
	
	return 0;
}
