#ifndef LIBRARY_H

#define LIBRARY_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// common abstract class for book, collection and journal
class Litra  
{
protected:
	vector <string> authors;
	string phouse;
	string name;
	int year;
	int pg;
public:
	Litra() : authors(0), phouse(""), name(""), year(0), pg(0) {}

	virtual void SetName(const string&) = 0;

	virtual void GetAuthors() const = 0;
	virtual void GetName() const = 0;

	virtual vector <string> Authors() const = 0;
	virtual string Name() const = 0;
	virtual string House() const = 0;
	virtual int Year() const = 0;
};

typedef pair<int, string> p;   // for content of book: 'page............name'

class Book: public Litra
{
private:
	vector <p> content;      // pair page-name
public:
	Book() : Litra(), content(0) {}
	
	void SetAuthors(vector <string>&);
	void SetAuthors(const string&);
	void SetContent(vector <p>&);
	void SetHouse(const string&);
	void SetName(const string&);
	void SetYear(int);
	void SetPages(int);

	void GetAuthors() const;
	void GetContent() const;
	void GetHouse() const;
	void GetName() const;
	void GetYear() const;
	void GetPages() const;

	vector <string> Authors() const;
	vector <p> Content() const;
	string House() const;
	string Name() const;
	int Year() const;
	int Pages() const;
};

class Collection: public Litra
{
private:
	vector <Book> books;
	int toms;
public:
	Collection() : Litra(), books(0), toms(0) {}

	void SetAuthors(vector <string>&);
	void SetAuthors(const string&);
	void SetBooks(vector <Book>&);
	void SetBooks(const Book&);
	void SetName(const string&);
	void SetToms(int);

	void RemBook(const Book &);  // remove book by its name

	void GetAuthors() const;
	void GetBooks() const;
	void GetName() const;
	void GetToms() const;

	vector <string> Authors() const;
	vector <Book> Books() const;
	string Name() const;
	string House() const;
	int Toms() const;
	int Year() const;
};

class Journal: public Litra
{
private:
	char per; // period - d/w/m/y
public:
	Journal () : Litra(), per('-') {}

	void SetHouse(const string&);
	void SetName(const string&);
	void SetPeriod(char);

	void GetAuthors() const;
	void GetHouse() const;
	void GetName() const;
	void GetPeriod() const;

	vector <string> Authors() const;
	string House() const;
	string Name() const;
	char Period() const;
	int Year() const;
};

// Библиотека должна предоставлять методы для удаления литературы из фондов библиотеки, 
// В случае выдачи читателям последнего экземпляра издания при поиске / просмотре экземпляр помечается как имеющийся в библиотеке, но находящийся на руках.
template <class T>
class Iterator;

class Library
{
private:
	map <Litra*, int> exes;
	set <Litra*> outer;
public:
	Library() : exes(), outer() {}

	void Add (Litra*);

	void GetLitra(Litra*);
	void GetOuters();
	
	void NameSearch(const string&);
	void AuthorSearch(const vector <string> &);
	void YearSearch(int);
	void HouseSearch(const string&);

	void RemLitra(Litra*);
};

template<class T>
class Iterator: public Library
{
private:
	T* current;
public:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef forward_iterator_tag iterator_category;
	typedef ptrdiff_t difference_type;

	Iterator(T* curr) : current(curr) {}
	Iterator& operator =(const Iterator& other)
	{
		if (this != &other)
		{
			current = other.current;
		}
		return *this;
	}
	Iterator& operator ++()
	{
		++current;
		return *this;
	}
	Iterator operator ++(int i)
	{
		Iterator tmp(current);
		++current;
		return tmp;
	}
	T& operator *()
	{
		return *current;
	}
	T* operator ->()
	{
		return current;
	}
	bool operator ==(const Iterator& other)
	{
		return current == other.current;
	}
	bool operator !=(const Iterator& other)
	{
		return !(*this == other);
	}
};

#endif /* LIBRARY_H */