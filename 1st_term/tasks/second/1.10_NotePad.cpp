#include <algorithm>
#include <iostream>
#include <sstream>  // stringstream
#include <vector>
#include <string>
#include <list>

using namespace std;

struct card
{  
	string name;   // Ololo
  	string number; // 154789
  	
  	card (string name, string num) : name(name), number(num) {}
  	card () : name(""), number("") {}
	
  	
  	bool operator != (const card &a) const
  	{
  		return !( *this == a );
	}
	
	bool operator == (const card &a) const
  	{
  		return ( name == a.name && number == a.number );
	}
	
	operator bool ()
	{
		return name.length();
	}
};

bool cmp (const card a, const card b)
{
  	return ( a.name <= b.name );
}

void sort (list <card> &db)
{
	db.sort(cmp);
}

vector<string> split (const string &s, char delim = ' ')
{
  	stringstream ss(s);
  	string item;
  	vector<string> elems;
  	
  	while ( getline(ss, item, delim) )
      	elems.push_back(item);
    
  	return elems;
}

string &tolower (string &s)
{
  	for (int i = 0; i < s.length(); i++)
		if ( 'A' <= s[i] && s[i] <= 'Z' )
      		s[i] -= 'A' - 'a';
  	return s; 
} 

void clear (list <card> &db)
{
  	int size = db.size();
  	
  	while ( size )
    {
      	db.pop_back();
      	size--;
    }
}

void print (list <card> &db)
{
	for (list<card>::iterator iter = db.begin(); iter != db.end(); iter++)
    {
		card c = *iter;
		cout << "Name: " << c.name << ". Phone: " << c.number << endl;
    }
}

card getcard (list <card> &db, string name)
{
  	card c;

  	for (list<card>::iterator iter = db.begin(); iter != db.end(); iter++)
    {

      	card cc = *iter;
      	if ( cc.name == name )
		{
	  		c = cc;
	  		break;
		}
    }
    
  	return c;
}

void insert (list <card> &db, string name, string phone)
{
	card c = getcard(db, name);
	
  	if ( c )
    {
      	cout << "Record already contains phone: " << c.number << endl;
      	cout << "Record updated: " << c.number << endl;
      	c.number = phone;
    }
  	else
    {
      	db.push_back(card(name, phone));
      	cout << "New record added" << endl;
    }
  	sort(db);
}

void find (list <card> &db, string name)
{
  	card c = getcard(db, name);
  	
  	if ( c == card("", "") )
    	cout << "Record not found" << endl;
  	else 
	  	cout << "Phone: " << c.number << endl;
}

int main (int argc, char *argv[])
{
  	cout << "Notepad" << endl;
  	
  	list <card> db;
  	string cmd;
  	
  	while ( true )
    {
      	cout << "Enter command: " << endl;
      	getline(cin, cmd);
      	if ( cmd == "exit" || !cin.good() )
			break;

      	//if (strlen(cmd) == 0)
      	//continue;

      	vector <string> args = split(cmd);
      	if ( !(args.size() >= 1 && args.size() <= 3) )
		{
	  		cout << "Wrong args" << endl;
	  		continue;
		}

      	tolower(args[0]);
      	if (args[0] == "insert")
			insert(db, args[1], args[2]);
      	else if (args[0] == "find")
			find(db, args[1]);
      	else if (args[0] == "print")
			print(db);
      	else 
		  	cout << "Wrong command" << endl;
      	
      	cout << endl;
    }
  
  	clear(db);
  	
  	return 0;
}
