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
	friend bigint subtract (const bigint& a, const bigint& b, bool& isMinus); // L - L (with sign)
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


bool operator == (const bigint& a, const bigint& b)
{
	if (a.amount != b.amount) 
		return false;

	for (int i = 0; i < a.amount; i++)
		if (a.digits[i] != b.digits[i]) 
			return false;

	return true;
}

bool operator != (const bigint& a, const bigint& b)
{
	return !(a == b);
}

bool operator > (const bigint& a, const bigint& b)
{
	if (a.amount != b.amount) 
		return a.amount > b.amount;

	for (int i = a.amount - 1; i >= 0; i--)
		if (a.digits[i] != b.digits[i])
			return a.digits[i] > b.digits[i];

	return false;
}

bool operator >= (const bigint& a, const bigint& b)
{
	return (a == b || a > b);
}

bool operator < (const bigint& a, const bigint& b)
{
	return !(a >= b);
}

bool operator <= (const bigint& a, const bigint& b)
{
	return !(a > b);
}

void operator += (bigint& a, int b)
{
	int pos = 0;

	a.digits[pos] += b;
	while (a.digits[pos] >= base)
	{
		a.digits[pos+1]++;
		a.digits[pos++] -= base;
	}

	if (a.digits[a.amount]) 
		a.amount++;
}

bigint operator + (const bigint& a, int b)
{
	bigint res = a;
	
	res += b;

	return res;
}

bigint operator + (const bigint& a, const bigint& b)
{
	bigint res;
	res.amount = max(a.amount, b.amount);

	int r = 0;
	for (int i = 0; (i < res.amount) | r; i++)
	{
		if (res.digits.size() <= i)
			res.digits.resize(res.digits.size() * 2);

		res.digits[i] = a.digits[i] + b.digits[i] + r;

		if (res.digits[i] >= base)
		{
			res.digits[i] -= base;
			r = 1;
		}
		else r = 0;
	}

	if (res.digits[res.amount])
		res.amount++;

	return res;
}

void operator -= (bigint& a, int b)
{
	int pos = 0;

	a.digits[pos] -= b;
	while (a.digits[pos] < 0)
	{
		a.digits[pos+1]--;
		a.digits[pos++] += base;
	}

	if (a.amount && !a.digits[a.amount-1]) 
		a.amount--;
}

bigint operator - (const bigint& a, int b)
{
	bigint res = a;
	
	res -= b;

	return res;
}

bigint operator - (const bigint& a, const bigint& b)
{
	bigint res = a;

	for (int i = 0; i < res.amount; i++)
	{
		res.digits[i] -= b.digits[i];

		if (res.digits[i] < 0)
		{
			res.digits[i+1]--;
			res.digits[i] += base;
		}
	}

	int pos = res.amount;
	while (pos && !res.digits[pos]) pos--;
	res.amount = pos + 1;

	return res;
}

bigint subtract (const bigint& a, const bigint& b, bool& isMinus)
{
	bigint res;

	if (a < b)
	{
		res = b - a;
		isMinus = true;
	}
	else
	{
		res = a - b;
		isMinus = false;
	}

	return res;
}

void operator *= (bigint& a, int b)
{
	int r = 0, i;
	for (i = 0; (i < a.amount) | r; i++)
	{
		a.digits[i] = a.digits[i] * b + r;
		r = a.digits[i] / base;
		a.digits[i] -= r * base;
	}

	a.amount = i;

	while (a.amount != 0 && !a.digits[a.amount-1]) 
		--a.amount;
}

bigint operator * (const bigint& a, int b)
{
	bigint res = a;

	res *= b;

	return res;
}

bigint operator * (const bigint& a, const bigint& b)
{
	bigint res;

	for (int i = 0; i < a.amount; i++)
	{
		int r = 0;
		for (int j = 0; (j < b.amount) | r; j++)
		{
			if (res.digits.size() <= i + j)
				res.digits.resize(res.digits.size()*2);

			res.digits[i+j] += a.digits[i] * b.digits[j] + r;
			r = res.digits[i+j] / base;
			res.digits[i+j] -= r * base;
		}
	}

	int pos = a.amount + b.amount;
	while (pos > 0 && !res.digits[pos]) pos--;
	res.amount = pos + 1;

	return res;
}

bigint operator / (const bigint& a, int b)
{
	bigint res;
	res.amount = a.amount;

	int r = 0;
	for (int i = res.amount-1; i >= 0; i--)
	{
		int cur = r * base + a.digits[i];
		res.digits[i] = cur / b;
		r = cur % b;
	}

	if (res.amount != 1 && !res.digits[res.amount - 1]) res.amount--;

	return res;
}

int operator % (const bigint& a, int b)
{
	int r = 0;

	for (int i = a.amount - 1; i >= 0; i--)
	{
		int cur = r * base + a.digits[i];
		r = cur % b;
	}

	return r;
}

void bigint::LevelUp()  // needs for division
{
	for (int i = amount; i >= 1; i--) digits[i] = digits[i - 1];
	if (digits[amount]) amount++;
}

bigint operator / (const bigint& a, const bigint& b)
{
	bigint res, curval;

	if (a < b)
	{
		res.digits[0] = 0;
		res.amount = 1;
		return res;
	}

	for (int i = a.amount-1; i >= 0; i--)
	{
		curval.LevelUp(); // * base
		curval.digits[0] = a.digits[i];
		
		int x = 0;
		int l = 0, r = base;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			bigint cur = b * m;
			if (cur <= curval)
			{
				x = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		res.digits[i] = x;
		curval = curval - b * x;
	}
	
	int pos = a.amount;
	while (pos >= 0 && !res.digits[pos]) pos--;
	res.amount = pos + 1;

	return res;
}

bigint operator % (const bigint& a, const bigint& b)
{
	bigint res, curval;

	for (int i = a.amount - 1; i >= 0; i--)
	{
		curval.LevelUp(); // *base
		curval.digits[0] = a.digits[i];
		
		int x = 0;
		int l = 0, r = base;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			bigint cur = b * m;
			if (cur <= curval)
			{
				x = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		res.digits[i] = x;
		curval = curval - b * x;
	}

	return curval;
}

istream& operator >> (istream& in, bigint& a)
{
	a.digits.resize(10000, 0);

	string s;
	cin >> s;

	int pos = 0;
	for (int i = s.length() - 1; i >= 0; i -= len)
	{
		int start = i - len + 1;
		if (start < 0) start = 0;
		string dig = s.substr(start, i - start + 1);
		a.digits[pos++] = atoi(dig.c_str());
	}

	a.amount = pos;

	return in;
}

ostream& operator << (ostream& o, bigint& a)
{
	printf("%d", a.digits[a.amount - 1]);
	for (int i = a.amount - 2; i >= 0; --i)
		printf(digform, a.digits[i]);
	printf("\n");

	return o;
}

int pow (const int& a, int n)
{
	int res = 1, t = n, cur = a;

	while (t)
	{
		if (t & 1) res *= cur;
		cur *= cur;
		t >>= 1;
	}

	return res;
}

bigint pow (const bigint& a, int b)
{
	bigint res(1), cur = a;
	int t = b;

	while (t)
	{
		if (t & 1) res = res * cur;
		cur = cur * cur;
		t >>= 1;
	}

	return res;
}

bigint fact (int n)
{
	bigint res(1);

	for (int i = 1; i <= n; i++) 
		res = res * i;

	return res;
}

int main()
{
	bigint a, b, c;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> a;
	cin >> b;
/*
	c = a + b;
	cout << c;

	if (a > b) c = a - b;
	else         c = b - a;
	cout << c;

	bool sign = false;
	c = subtract(a, b, sign);
	if (sign) cout << '-';
	cout << c;

	c = a * b;
	cout << c;

	c = a / b;
	cout << c;
*/
	c = a % b;
	cout << c;
/*
	cout << fact(1000);
*/
	return 0;
}
