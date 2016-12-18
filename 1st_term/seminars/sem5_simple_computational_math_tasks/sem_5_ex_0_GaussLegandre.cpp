// 05_seminar.zip
//#include <std_facilities.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Point
{
	double xi;
	double w;
};

class GaussLegendre
{
private:
	vector <Point> points;
public:
	GaussLegendre (const string filename)
	{
		ifstream ifs(filename.c_str());
		//if ( !ifs ) error("Can`t open file'" + filename + "'");
		Point p;
		while ( ifs >> p.xi >> p.w )
			points.push_back(p);
	}

	double integrate (double f(double), double a, double b)
	{
		double kk = 0.5*(b-a);
		double bb = 0.5*(b+a);
		double s = 0.;
	
		for (size_t i = 0; i < points.size(); i++)
		{
			s += points[i].w * f(kk * points[i].xi + bb);
		}

		return kk * s;
	}
};

double polynom (double x);

int main()
{
	double a = 1.0, b = 100.0;
	
	GaussLegendre gale("gauss_legendre_n10.txt");
	
	double I = gale.integrate(polynom, a, b);
	
	cout << "I = " << I << "\n";
	
	return 0;
}

double polynom (double x)
{
	return pow(x, 2) + x;
}
