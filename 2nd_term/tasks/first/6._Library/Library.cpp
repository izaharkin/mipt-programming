#include "Library.h"

bool operator == (const vector <string> &a, const vector <string> &b)
{
	bool flag = false;

	for (vector <string>::const_iterator i = b.begin(); !flag && i != b.end(); ++i)
		if (*i == a[0])
			flag = true;

	return flag;
}

void Book::SetAuthors(const string& a)
{
	authors.push_back(a);
}

void Book::SetAuthors(vector <string>& a)
{
	for (vector <string>::iterator i = a.begin(); i != a.end(); ++i)
		authors.push_back(*i);
}

void Book::SetContent(vector <p>& a)
{
	for (vector <p>::iterator i = a.begin(); i != a.end(); ++i)
		content.push_back(*i);
}

void Book::SetHouse(const string& _phouse)
{
	phouse = _phouse;
}

void Book::SetName(const string& _name)
{
	name = _name;
}

void Book::SetYear(int _year)
{
	year = _year;
}

void Book::SetPages(int _pg)
{
	pg = _pg;
}

void Book::GetAuthors() const
{
	cout << "Book \"" << name << "\" has following authors:\n";
	for (vector <string>::const_iterator i = authors.begin(); i != authors.end(); ++i)
		cout << *i << "\n";
}

void Book::GetContent() const
{
	cout << "Book \"" << name << "\" has the following content:\n";
	for (vector <p>::const_iterator i = content.begin(); i != content.end(); ++i)
		cout << (*i).first << "..........." << (*i).second << "\n";
}

void Book::GetHouse() const
{
	cout << "Book \"" << name << "\" was published by " << phouse << " publishing house\n";
}

void Book::GetName() const
{
	cout << "Name of this book is \"" << name << "\"\n";
}

void Book::GetYear() const
{
	cout << "Book \"" << name << "\" was published in " << year << "\n";
}

void Book::GetPages() const
{
	cout << "Book \"" << name << "\" has " << pg << " pages\n";
}

vector <string> Book::Authors() const
{
	return authors;
}

vector <p> Book::Content() const
{
	return content;
}

string Book::House() const
{
	return phouse;
}

string Book::Name() const
{
	return name;
}

int Book::Year() const
{
	return year;
}

int Book::Pages() const
{
	return pg;
}

void Collection::SetAuthors(vector <string>& a)
{
	for (vector <string>::iterator i = a.begin(); i != a.end(); ++i)
		authors.push_back(*i);
}

void Collection::SetAuthors(const string& a)
{
	authors.push_back(a);
}

void Collection::SetBooks(const Book& _book)
{
	books.push_back(_book);
}

void Collection::SetBooks(vector <Book>& _books)
{
	for (vector <Book>::iterator i = _books.begin(); i != _books.end(); ++i)
		books.push_back(*i);
}

void Collection::SetName(const string& _name)
{
	name = _name;
}

void Collection::SetToms(int _toms)
{
	toms = _toms;
}

void Collection::RemBook (const Book& _book)
{
	vector <Book>::iterator j;
	for (vector <Book>::iterator i = books.begin(); i != books.end(); ++i)
	{
		if (i->Name() == _book.Name())
		{
			j = i;
			break;
		}
	}
	books.erase(j);
}

void Collection::GetAuthors() const
{
	cout << "Collection \"" << name << "\" has following authors:\n";
	for (vector <string>::const_iterator i = authors.begin(); i != authors.end(); ++i)
		cout << *i << "\n";
}

void Collection::GetBooks() const
{
	cout << "Collection \"" << name << "\" includes following books:\n";
	for (vector <Book>::const_iterator i = books.begin(); i != books.end(); ++i)
		cout << i->Name() << "\n";
}

void Collection::GetName() const
{
	cout << "Name of this collection is \"" << name << "\"\n";
}

void Collection::GetToms() const
{
	cout << "The quantity of toms in collection \"" << name << "\" is " << toms << " \n";
}

vector <string> Collection::Authors() const
{
	return authors;
}

vector <Book> Collection::Books() const
{
	return books;
}

string Collection::Name() const
{
	return name;
}

string Collection::House() const
{
	return "";
}

int Collection::Toms() const
{
	return toms;
}

int Collection::Year() const
{
	return -1;
}

void Journal::SetHouse(const string& _phouse)
{
	phouse = _phouse;
}

void Journal::SetName(const string& _name)
{
	name = _name;
}

void Journal:: SetPeriod(char _per)
{
	per = _per;
}

void Journal::GetAuthors() const
{
	cout << "Journals haven`t authors :)\n";
}

void Journal::GetHouse() const
{
	cout << "Journal \"" << name << "\" was published by " << phouse << " publishing house\n";
}

void Journal::GetName() const
{
	cout << "Name of this journal is \"" << name << "\"\n";
}

void Journal::GetPeriod() const
{
	cout << "The journal \"" << name << "\" comes every " << (per == 'd' ? "day" : (per == 'w' ? "week" : (per == 'm' ? "month" : "year"))) << "\n";
}

vector <string> Journal::Authors() const
{
	vector <string> vec(0);
	return vec;
}

string Journal::House() const
{
	return phouse;
}

string Journal::Name() const
{
	return name;
}

char Journal::Period() const
{
	return per;
}

int Journal::Year() const
{
	return -1;
}

void Library::Add(Litra *l)
{
	if (exes.find(l) == exes.end())
		exes[l] = 1;
	else
		exes[l]++;
}

void Library::GetLitra(Litra *l)
{
	if ( exes.find(l) != exes.end() )
	{
		if (exes[l])
		{
			exes[l]--;
			outer.insert(l);
		}
		else
			cout << "All exemplars are out of library\n\n";
	}
	else
		cout << "There is no such literature in library at all\n\n";
}

void Library::GetOuters()
{
	if (outer.size())
	{
		cout << "It is the list of laterature, that is not int the library now:\n";
		for (set <Litra*>::const_iterator i = outer.begin(); i != outer.end(); ++i)
		{
			(*i)->GetName();
			(*i)->GetAuthors();
		}
	}
	else
		cout << "All literature is in the library\n";
}

void Library::NameSearch(const string& _name)
{
	bool flag = false;

	for (map<Litra*, int>::iterator i = exes.begin(); i != exes.end(); ++i)
	{
		const Litra *t = i->first;
		if ( (i->first)->Name() == _name )
		{
			const Book *is_book = dynamic_cast<const Book*> (t);
			if (is_book != NULL)
			{
				flag = true;
				cout << "There is the book with this name in the library, here is its info:\n";
				is_book->GetName();
				is_book->GetAuthors();
				is_book->GetHouse();
				is_book->GetPages();
				is_book->GetYear();
			}
			else
			{
				const Collection *is_coll = dynamic_cast<const Collection*> (t);
				if (is_coll != NULL)
				{
					flag = true;
					cout << "There is the collection with this name in the library, here is its info:\n";
					is_coll->GetName();
					is_coll->GetAuthors();
					is_coll->GetBooks();
					is_coll->GetToms();
				}
				else
				{
					const Journal *is_j = dynamic_cast<const Journal*> (t);
					if (is_j != NULL)
					{
						flag = true;
						cout << "There is the journal with this name in the library, here is its info:\n";
						is_j->GetName();
						is_j->GetHouse();
						is_j->GetPeriod();
					}
				}
			}
		}
	}

	if (!flag)
		cout << "Sorry, but there`s no literature with this name\n";
	cout << "\n";
}

void Library::AuthorSearch(const vector <string> &_a)
{
	bool flag = false;

	for (map<Litra*, int>::iterator i = exes.begin(); i != exes.end(); ++i)
	{
		const Litra *t = i->first;
		if ((i->first)->Authors() == _a)
		{
			flag = true;
			const Book *is_book = dynamic_cast<const Book*> (t);
			if (is_book != NULL)
			{
				cout << "There is the book with this name in the library, here is its info:\n";
				is_book->GetName();
				is_book->GetAuthors();
				is_book->GetHouse();
				is_book->GetPages();
				is_book->GetYear();
				cout << "\n";
			}
			else
			{
				const Collection *is_coll = dynamic_cast<const Collection*> (t);
				if (is_coll != NULL)
				{
					flag = true;
					cout << "There is the collection with this name in the library, here is its info:\n";
					is_coll->GetName();
					is_coll->GetAuthors();
					is_coll->GetBooks();
					is_coll->GetToms();
					cout << "\n";
				}
				else
				{
					const Journal *is_j = dynamic_cast<const Journal*> (t);
					if (is_j != NULL)
					{
						flag = true;
						cout << "There is the journal with this name in the library, here is its info:\n";
						is_j->GetName();
						is_j->GetHouse();
						is_j->GetPeriod();
						cout << "\n";
					}
				}
			}
		}
	}

	if (!flag)
		cout << "Sorry, but there`s no literature with this author(s)\n\n";
}

void Library::YearSearch(int _year)
{
	bool flag = false;

	for (map<Litra*, int>::iterator i = exes.begin(); i != exes.end(); ++i)
	{
		const Litra *t = i->first;
		if ((i->first)->Year() == _year)
		{
			flag = true;
			const Book *is_book = dynamic_cast<const Book*> (t);
			if (is_book != NULL)
			{
				cout << "There is the book with this year in the library, here is its info:\n";
				is_book->GetName();
				is_book->GetAuthors();
				is_book->GetHouse();
				is_book->GetPages();
				is_book->GetYear();
				cout << "\n";
			}
			else
			{
				const Collection *is_coll = dynamic_cast<const Collection*> (t);
				if (is_coll != NULL)
				{
					flag = true;
					cout << "There is the collection with this year in the library, here is its info:\n";
					is_coll->GetName();
					is_coll->GetAuthors();
					is_coll->GetBooks();
					is_coll->GetToms();
					cout << "\n";
				}
				else
				{
					const Journal *is_j = dynamic_cast<const Journal*> (t);
					if (is_j != NULL)
					{
						flag = true;
						cout << "There is the journal with this year in the library, here is its info:\n";
						is_j->GetName();
						is_j->GetHouse();
						is_j->GetPeriod();
						cout << "\n";
					}
				}
			}
		}
	}

	if (!flag)
		cout << "Sorry, but there`s no literature with this year\n\n";
}

void Library::HouseSearch(const string & _phouse)
{
	bool flag = false;

	for (map<Litra*, int>::iterator i = exes.begin(); i != exes.end(); ++i)
	{
		const Litra *t = i->first;
		if ((i->first)->House() == _phouse)
		{
			flag = true;
			const Book *is_book = dynamic_cast<const Book*> (t);
			if (is_book != NULL)
			{
				cout << "There is the book with this printing house in the library, here is its info:\n";
				is_book->GetName();
				is_book->GetAuthors();
				is_book->GetHouse();
				is_book->GetPages();
				is_book->GetYear();
				cout << "\n";
			}
			else
			{
				const Collection *is_coll = dynamic_cast<const Collection*> (t);
				if (is_coll != NULL)
				{
					flag = true;
					cout << "There is the collection with this printing house in the library, here is its info:\n";
					is_coll->GetName();
					is_coll->GetAuthors();
					is_coll->GetBooks();
					is_coll->GetToms();
					cout << "\n";
				}
				else
				{
					const Journal *is_j = dynamic_cast<const Journal*> (t);
					if (is_j != NULL)
					{
						flag = true;
						cout << "There is the journal with this printing house in the library, here is its info:\n";
						is_j->GetName();
						is_j->GetHouse();
						is_j->GetPeriod();
						cout << "\n";
					}
				}
			}
		}
	}

	if (!flag)
		cout << "Sorry, but there`s no literature with this printing house\n\n";
}

void Library::RemLitra(Litra *a)
{
	if (exes.find(a) != exes.end())
		exes.erase(a);
	else
		cout << "There is no such literature in the library at all\n";
}
