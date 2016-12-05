#include <iostream>

using namespace std;

class Box
{
private:
	double a, b, c;
public:
	Box ();
	Box (double aa, double bb, double cc);
	
	void input    ();
	double volume ();	
	bool fit      (Box box);
};

Box:: Box  ()
{
	a = b= c = 0;
}

Box:: Box  (double aa, double bb, double cc)
{
	a = aa;
	b = bb;
	c = cc;
}

void Box:: input ()
{
	int x, y, z;
	
	cin >> x >> y >> z;
	
	a = x;
	b = y;
	c = z;
}

double Box:: volume ()
{
		return a * b * c;
}
	
bool Box:: fit (Box box)
{
	return ( box.a <= a && box.b <= b && box.c <= c || 
		 	 box.a <= b && box.b <= c && box.c <= a ||
		 	 box.a <= c && box.b <= a && box.c <= b ||
		 	 box.a <= c && box.b <= b && box.c <= a ||
		 	 box.a <= b && box.b <= a && box.c <= c ||
			 box.a <= a && box.b <= c && box.c <= b    );
}

int main()
{
	Box a, b;
	
	a.input();
	b.input();
	
	cout << (a.fit(b) ? "Yes" : "No");
	
	return 0;
}
