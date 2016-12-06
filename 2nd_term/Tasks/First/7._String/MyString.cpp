#include "MyString.h"

char* my_cpy(char *dest, const char *source)
{
	if (source != NULL)
	{
		dest = new char[(strlen(source) + 1) * sizeof(char)];
		for (size_t i = 0; i < strlen(source); ++i)
			dest[i] = source[i];
		dest[strlen(source)] = '\0';
	}
	return dest;
}

mstring::mstring(const char* s)
{
	if (s != NULL)
	{
		str = (char *)malloc((strlen(s) + 1) * sizeof(char));
		str = my_cpy(str, s);
		len = strlen(s);
		mem = len * 2;
	}
}

mstring::mstring(const mstring& s)
{
	str = new char[(s.length() + 1)*sizeof(char)];
	str = my_cpy(str, s.str);
	len = s.len;
	mem = s.mem;
}

mstring::mstring(const std::string& s)
{
	str = new char[(s.length() + 1)*sizeof(char)];
	size_t i;
	for (i = 0; i < s.length(); ++i)
		str[i] = s[i];
	str[i] = '\0';
	len = s.length();
}

const char* mstring::c_str() const
{ 
	return str ? str : ""; 
}

size_t mstring::length() const
{
	return len;
}

char& mstring::operator [] (size_t i) const
{
	return str[i];
}

void mstring::append(char c)
{
	if (mem < len + 1) 
	{
		if (str == NULL) 
		{
			str = (char*) malloc((len + 1) * sizeof(char));
			mem = len + 1;
		}
		else 
		{
			char* test = (char*) realloc(str, mem * 2 * sizeof(char));
			if (test == NULL) 
			{
				std::cout << "append(): can't allocate the memory\n";
				return;
			}
			else
				str = test;
			mem <<= 1;
		}
	}
	str[len++] = c;
}

void mstring::insert(int index, char c) 
{
	if (mem < len + 1) 
	{
		if (str == NULL) 
		{
			str = (char*) malloc((len + 1) * sizeof(char));
			mem = len + 1;
		}
		else 
		{
			char* test = (char*) realloc(str, (mem + 1) * 2 * sizeof(char));
			if (test == NULL) 
			{
				std::cout << "insert(): can't allocate the memory\n";
				return;
			}
			else
				str = test;
			mem = (mem + 1) * 2;
		}
	}
	len++;
	memmove(str + (index + 1) * sizeof(char), str + index * sizeof(char), (len - index) * sizeof(char));
	str[index] = c;
}

void mstring::pop_back() 
{
	if (len == 0) 
	{
		std::cout << "pop_back(): string is empty\n";
		return;
	}

	str[len-- - 1] = 0;
	if (len * 2 < mem) 
	{
		mem >>= 1;
		char* test = (char*) realloc(str, mem  * sizeof(char));
		if (test == NULL) 
		{
			std::cout << "pop_back(): can't allocate the memory\n";
			return;
		}
		else
			str = test;
	}
}

void mstring::setlen(int n)
{
	len = n;
}

void mstring::setstr(int n)
{
	str = new char[n + 1];
}

void mstring::delstr()
{
	delete[] str;
}

mstring mstring::operator = (const mstring& s)
{
	if (s.mem > mem)
	{
		char* test = (char*)realloc(str, s.mem * sizeof(char));
		if (test == NULL)
		{
			std::cout << "Error: can't allocate memory.\n";
			return 0;
		}
		else
			str = test;
		mem = s.mem;
	}

	str = my_cpy(str, s.str);
	len = s.len;

	return *this;
}

bool operator == (const mstring& s1, const mstring& s2)
{
	if (s1.len == s2.len)
	{
		for (size_t i = 0; i < s1.len; ++i)
			if (s1[i] != s2[i])
				return false;
		return true;
	}
	return false;
}

bool operator != (const mstring& s1, const mstring& s2)
{
	return !(s1 == s2);
}

bool operator < (const mstring& s1, const mstring& s2)
{
	if (s1.len == s2.len)
	{
		for (size_t i = 0; i < s1.len; ++i)
			if (s1[i] > s2[i])
				return false;
		return true;
	}
	else
		return s1.len < s2.len;
}

bool operator <= (const mstring& s1, const mstring& s2)
{
	return (s1 == s2 || s1 < s2);
}

bool operator > (const mstring& s1, const mstring& s2)
{
	return !(s1 <= s2);
}

bool operator >= (const mstring& s1, const mstring& s2)
{
	return !(s1 < s2);
}