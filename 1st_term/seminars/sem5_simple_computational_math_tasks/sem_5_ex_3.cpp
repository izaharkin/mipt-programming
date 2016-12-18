// 05_seminar.zip
//#include <std_facilities.h>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
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

double a1(double);
double a2(double);
double a3(double);
double a4(double);
double bb(double);
double c(double);
double d(double);

int main()
{
	double a, b, I;
	GaussLegendre gale("gauss_legendre_n10.txt");
	
	cout.precision(12);
	
	a = 0, b = 1;
	I = gale.integrate(a1, a, b);
	cout << I << "\n";
	
	a = 0, b = 1;
	I = gale.integrate(a2, a, b);
	cout << I << "\n";
	
	a = 0, b = 1;
	I = gale.integrate(a3, a, b);
	cout << I << "\n";
	
	a = 0, b = 1;
	I = gale.integrate(a4, a, b);
	cout << I << "\n";
	
	a = 0, b = 1;
	I = gale.integrate(bb, a, b);
	cout << I << "\n";
	
	a = 0, b = 1;
	I = gale.integrate(c, a, b);
	cout << I << "\n";
	
	a = 1, b = 2;
	I = gale.integrate(d, a, b);
	cout << I << "\n";
	
	return 0;
}

double a1 (double x)
{
	return pow(x, 3);
}

double a2 (double x)
{
	return pow(x, 7);
}

double a3 (double x)
{
	return pow(x, 19);
}

double a4 (double x)
{
	return pow(x, 12);
}

double bb (double x)
{
	return pow(x, 5) + 0.28*pow(x, 4) - 0.499*x - 3.44;
}

double c (double x)
{
	return pow(x, 10) + 5*pow(x, 7) - 2*pow(x, 3) + x - 1; 
}

double d (double x)
{
	return -pow(x, 18) + 6.8*pow(x, 16) - 2*pow(x, 5) + x - 1;
}
