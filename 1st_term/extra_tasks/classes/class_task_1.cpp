#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Abitur
{
private:
	string fio;
	string depart;
	int spec;
	int points;
	bool medal;
public:
	Abitur ();
	
	Abitur (string, string, int, int, bool);
	
	void dep_info   ();
	void dep_change (string);
	
	void spec_info   ();
	void spec_change (int s);
	
	void output    ();
	void got_medal ();
	
	bool operator < (const Abitur&);
	bool operator > (const Abitur&);
	bool operator == (const Abitur&);
};

Abitur:: Abitur () 
	{
		fio = ""; 
		depart = ""; 
		spec = 0; 
		points = 0;
		medal = false; 
	}
	
Abitur:: Abitur (string f, string d, int s, int p, bool m)
{
	fio = f;
	depart = d;
	spec = s;
	points = p;
	medal = m;
}
	
void Abitur:: dep_info ()
{
	cout << depart << "\n";
}
	
void Abitur:: dep_change (string d)
{
	depart = d;
}
	
void Abitur:: spec_info ()
{
	cout << spec << "\n";
}
	
void Abitur:: spec_change (int s)
{
	spec = s;
}
	
void Abitur:: output ()
{
	cout << fio << "\n" 
		 << depart << "\n" 
	     << spec << "\n" 
	     << points << "\n"
		 << (medal ? "Yes" : "No") << "\n";
}
	
void Abitur:: got_medal ()
{
	cout << (medal ? "Yes" : "No");
}

bool Abitur:: operator < (const Abitur& a)
{
	return ( points < a.points );
}

bool Abitur:: operator > (const Abitur& a)
{
	return ( points > a.points );
}

bool Abitur:: operator == (const Abitur& a)
{
	return ( points == a.points );
}

int main()
{
	
	
	return 0;
}
