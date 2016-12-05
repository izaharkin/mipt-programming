#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Address
{
private:
	char *zip, *street, *city, *region;
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

int main()
{
	char *Z = new char[50], *S = new char[50], *C = new char[50], *R = new char[50];
	int H;
	
	scanf("%s", Z);
	scanf("%s", S);
	scanf("%s", C);
	scanf("%s", R);
	scanf("%d", &H);
	
	Address a(Z, S, C, R, H);
	Address b;
	
	b = a;
	
	a.print();
	b.print();
	
	return 0;
}
