#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool pal_check (const string& str)
{
	int i = 0, j = str.length() - 1;
	bool flag = true;
	
	while ( flag && i <= j )
		flag = (str[i++] == str[j--]);
	
	return flag;
}

int main()
{
	vector <string> pals;
	string str;
	
	while ( true )
	{
		cin >> str;
		if ( str == "w" )
		{
			cin >> str;
			if ( pal_check(str) )
				pals.push_back(str);
		}
		else if ( str == "p" )
		{
			for (int i = 0; i < pals.size(); ++i)
				cout << pals[i] << " ";
			cout << "\n";
		}
		else 
			break;
	}
	
	return 0;
}
