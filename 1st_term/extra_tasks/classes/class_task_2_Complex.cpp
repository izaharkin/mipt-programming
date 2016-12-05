#include <iostream>

using namespace std;

class Complex
{
private:
	double re;
	double im;
public:
	Complex ();
	Complex (double, double);
	
	friend Complex operator + (const Complex&, const Complex&);
	friend Complex operator + (const Complex&, const double&);
	
	friend Complex operator - (const Complex&, const Complex&);
	friend Complex operator - (const Complex&, const double&);
	
	friend Complex operator * (const Complex&, const Complex&);
	friend Complex operator * (const Complex&, const double&);
};

Complex:: Complex ()
{
	re = im = 0;
}
Complex:: Complex (double r, double i)
{
	re = r;
	im = i;
}

Complex operator + (const Complex& a, const Complex& b)
{
	Complex c;
	
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	
	return c;
}

Complex operator + (const Complex& a, const double& b)
{
	Complex c;
	
	c.re = a.re + b;
	
	return c;
}

Complex operator - (const Complex& a, const Complex& b)
{
	Complex c;
	
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	
	return c;
}

Complex operator - (const Complex& a, const double& b)
{
	Complex c;
	
	c.re = a.re - b;
	
	return c;
}

Complex operator * (const Complex& a, const Complex& b)
{
	Complex c;
	
	
	
	return c;
}

Complex operator * (const Complex& a, const double& b)
{
	Complex c;
	
	c.re = a.re * b;
	
	return c;
}

int main()
{
	Complex a, b, c;
	
	
	
	c = a + b;
	
	return 0;
}
