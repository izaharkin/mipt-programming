#include "Library.h"

int main ()
{
	Book a, b;

	a.SetAuthors("Lev Landau");
	
	vector <p> content;
	content.push_back(make_pair(1, "Beginning"));
	content.push_back(make_pair(3, "Get started"));
	content.push_back(make_pair(1500, "The end"));
	a.SetContent(content);
	
	a.SetHouse("MIPT");
	a.SetName("Mechanics");
	a.SetYear(1967);
	a.SetPages(1500);

	a.GetAuthors();
	a.GetContent();
	a.GetHouse();
	a.GetName();
	a.GetYear();
	a.GetPages();
	cout << "\n";
////////////////////////////////////////////////////////////////////////////////
	b.SetAuthors("Lev Landau");
	b.SetContent(content);
	b.SetHouse("MIPT");
	b.SetName("Termodynamics");
	b.SetYear(1967);
	b.SetPages(1800);

	b.GetAuthors();
	b.GetContent();
	b.GetHouse();
	b.GetName();
	b.GetYear();
	b.GetPages();
	cout << "\n";
////////////////////////////////////////////////////////////////////////////////
	Collection c;

	c.SetAuthors("Lev Landau");

	c.SetName("Theoretical physics");
	c.SetBooks(a);
	c.SetBooks(b);
	c.SetToms(10);

	c.GetAuthors();
	c.GetName();
	c.GetBooks();
	c.GetToms();
	cout << "\n";

	c.RemBook(b);

	c.GetBooks();
	cout << "\n";
////////////////////////////////////////////////////////////////////////////////
	Journal j;

	j.SetName("Mozaik");
	j.SetHouse("DeAgostini");
	j.SetPeriod('w');

	j.GetName();
	j.GetHouse();
	j.GetPeriod();
	cout << "\n";
////////////////////////////////////////////////////////////////////////////////
	Library Lib;

	Lib.Add(&a);
//	Lib.Add(&a);
	Lib.Add(&b);
	Lib.Add(&c);
	Lib.Add(&j);

	Lib.NameSearch("Mechanics");
	Lib.NameSearch("Theoretical physics");
	Lib.NameSearch("Mozaik");
///////////////////////////////////////////
	vector <string> vec;
	vec.push_back("Lev Landau");

//	Lib.AuthorSearch(vec);
///////////////////////////////////////////
	Lib.YearSearch(1967);
	Lib.YearSearch(2005);
	Lib.YearSearch(0);
///////////////////////////////////////////
	Lib.HouseSearch("MIPT");
	Lib.HouseSearch("Moskva");
	Lib.HouseSearch("DeAgostini");
///////////////////////////////////////////
	Lib.GetLitra(&a);
	Lib.GetOuters();
	Lib.GetLitra(&a);

	Lib.GetLitra(&b);
	Lib.GetOuters();

	system("PAUSE");

	return 0;
}