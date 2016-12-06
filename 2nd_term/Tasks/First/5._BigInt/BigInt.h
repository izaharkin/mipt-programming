#ifndef BIGINT_H

#define BIGINT_H

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>

#define len 4                // for sqrt - 2, usually - 4
#define max_sz 10000         // for sqrt - 6105, usually 10000
#define digform "%.4d"       // for sqrt - "%.1d", usually - "%.4d"
const int base = (int) 1e4;  // for sqrt - 1e1, usually - 1e4

using namespace std;

const char ch[36] =          // for different numeric systems 
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z'
};

class bigint
{
private:
	vector <int> digits;
	int amount;
public:
	bigint()
	{
		digits.resize(10000, 0);
		amount = 1;
	}

	bigint(int n)
	{
		digits.resize(10000, 0);
		int t = n, pos = 0;

		while (t)
		{
			digits[pos++] = t % base;
			t /= base;
		}

		amount = pos;
	}

	bigint(const string& s)
	{
		digits.resize(10000, 0);

		int pos = 0;
		for (int i = s.length() - 1; i >= 0; i -= len)
		{
			int start = i - len + 1;
			if (start < 0) start = 0;
			string dig = s.substr(start, i - start + 1);
			digits[pos++] = atoi(dig.c_str());
		}

		amount = pos;
	}

	bigint(const bigint& a)
	{
		digits.resize(10000, 0);
		amount = a.amount;
		for (int i = 0; i < amount; ++i)
			digits[i] = a.digits[i];
	}
	
	// comparison
	friend bool operator == (const bigint& a, const bigint& b);
	friend bool operator != (const bigint& a, const bigint& b);
	friend bool operator >  (const bigint& a, const bigint& b);
	friend bool operator >= (const bigint& a, const bigint& b);
	friend bool operator <  (const bigint& a, const bigint& b);
	friend bool operator <= (const bigint& a, const bigint& b);
	// addition
	friend bigint operator + (const bigint& a, const bigint& b); // L + L
	friend bigint operator + (const bigint& a, int b);    // L + S
	friend bigint operator + (const int& b, const bigint& a);    // S + L
	// subtraction
	friend bigint operator - (const bigint& a, const bigint& b); // L - L (L1 >= L2)
	friend bigint operator - (const bigint &a, int n);    // L - S
	friend bigint subtract (const bigint& a, const bigint& b, bool isMinus); // L - L (with sign)
	// multiplying
	friend bigint operator * (const bigint& a, const bigint& b); // L * L
	friend bigint operator * (const bigint& a, int n);    // L * S
	// division
	void LevelUp();
	friend bigint operator / (const bigint& a, const bigint& b); // L / L
	friend bigint operator / (const bigint& a, int b);    // L / S
	friend bigint operator % (const bigint& a, const bigint& b); // L % L
	friend int operator % (const bigint& a, int b);       // L % S
	// special operators
	friend void operator += (bigint& a, int b);      // L += S
	friend void operator -= (bigint& a, int b);      // L -= S
	friend void operator *= (bigint& a, int b);		// L *= S
	friend void operator /= (bigint& a, int b);		// L /= S
	friend void operator %= (bigint& a, int b);		// L %= S
	// increment, decrement
	friend bigint& operator ++ (bigint& a);                 // L++ (TODO)
	friend bigint& operator -- (bigint& a);                 // L-- (TODO)
	// stream operators
	friend istream& operator >> (istream&, bigint&);
	friend ostream& operator << (ostream&, bigint&);
	// degree (power)
	friend int pow(int a, int n);             // S ^ S
	friend bigint pow(const bigint& a, int b);       // L ^ S
	// factorial
	friend bigint fact(int n);                       // S!
	// square root
	void shift(int pos, int lastdigit);
	bigint sqrt() const;
	// numeric system conversion
	string DecToMy(const bigint& n, const bigint& b);
	int MyToDec(const string& s, const bigint& b);
};

#endif /* BIGINT_H */
