#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Address
{
private:
	char *name, *zip, *street, *city, *region;
	int house;
public:
	Address ()
	{
		zip = NULL;
		street = NULL;
		city = NULL;
		region = NULL;
		house = -1;
	}
	
	Address (Address& wtf)
	{
		zip = new char[strlen(wtf.zip)+1]; 
		strcpy(zip, wtf.zip);
		
		street = new char[strlen(wtf.street)+1]; 
		strcpy(street, wtf.street);
		
		city = new char[strlen(wtf.city)+1]; 
		strcpy(city, wtf.city);
		
		region = new char[strlen(wtf.region)+1]; 
		strcpy(region, wtf.region);
		
		house = wtf.house;
	}
	
	Address (char *_zip, char *_street, char *_city, char *_region, int _house)
	{
		zip = new char[strlen(_zip)+1];
		strcpy(zip, _zip);
		
		street = new char[strlen(_street)+1];
		strcpy(street, _street);
		
		city = new char[strlen(_city)+1]; 
		strcpy(city, _city);
		
		region = new char[strlen(_region)+1];
		strcpy(region, _region);
		
		house = _house;
	}
	
	~Address ()
	{
		delete[] zip;
		delete[] street;
		delete[] city;
		delete[] region;
	}
	
	void print ()
	{
		printf("%s ", zip);
		printf("%s ", street);
		printf("%s ", city);
		printf("%s ", region);
		printf("%d \n", house);
	}
};

class Human
{
public:
	char *name;
	Address add;	
};

void Input (char *z, char *s, char *c, char *r, int h)
{
	scanf("%s", z);
	scanf("%s", s);
	scanf("%s", c);
	scanf("%s", r);
	scanf("%d", &h);
}

int main()
{
	char c, *name, *z, *s, *cc, *r;
	int h, k = 0;
	Human a[64];
	
	while ( true )
	{
		cin >> c;
		switch ( c )
		{
			case 'i': {
				cout << "Enter the name: ";
				scanf("%s", name);
				cout << "Enter the address: ";
				Input(z, s, cc, r, h);
				Address t(z, s, cc, r, h);
				a[k++].name = name;	
				a[k++].add = t;				
				break;
			}
			case 'q': {
				
				break;
			}
			case 'f': {
				
				break;
			}
			default:
				return 0;
		}
	}
}
