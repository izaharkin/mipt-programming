#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;

class mstring
{
private:
	char *str;
	size_t len;
	size_t mem;
public:
	mstring() : len(0), mem(0) {}
	mstring(const char*);
	mstring(const mstring&);
	mstring(const std::string&);

	const char* c_str() const;
	size_t length() const;
	char& operator [] (size_t i) const;

	void append(char);
	void insert(int, char);
	void pop_back();

	void setlen(int);
	void setstr(int);
	void delstr();

	friend std::istream& operator >> (std::istream& in, mstring& s)
	{
		char c;
		in.get(c);
		while (c != ' ' && c != '\n') 
		{
			s.append(c);
			in.get(c);
		}
		return in;
	}
	friend std::ostream& operator << (std::ostream& o, const mstring& s)
	{
		for (size_t i = 0; i < s.length(); ++i)
			o << s[i];
		return o;
	}

	friend char* my_cpy(char *, const char *);
	mstring operator = (const mstring& s);
	mstring& operator + (const mstring&);
	friend bool operator == (const mstring&, const mstring&);
	friend bool operator != (const mstring&, const mstring&);
	friend bool operator < (const mstring&, const mstring&);
	friend bool operator <= (const mstring&, const mstring&);
	friend bool operator > (const mstring&, const mstring&);
	friend bool operator >= (const mstring&, const mstring&);

	~mstring()
	{
		delete[] str;
	}
};