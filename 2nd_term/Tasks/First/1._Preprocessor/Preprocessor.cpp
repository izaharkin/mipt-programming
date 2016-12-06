/* Task: Doing my own preprocessor:
1. Delete all commentaries
2. Write my own #define A B // swap A and B
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
//  Deleting commentaries
	string s = "", t;
	while ( getline(ifs, t) )
	{
		s += t;
		if ( s[s.length()-1] != '@' )
			s += '@';
	}
	cout << s << "\n";//
	
	string op_com = "/", cl_com = "*/";
	int cur_com_pos = s.find(op_com);
	while ( cur_com_pos != string::npos )
	{
		if ( s[cur_com_pos+1] == '/' )
		{
			int end_str = s.find("@", cur_com_pos+2);
			s.erase(cur_com_pos, end_str+1 - cur_com_pos);
		}
		else if ( s[cur_com_pos+1] == '*' )
		{
			int cur_cl_pos = s.find(cl_com);
			s.erase(cur_com_pos, cur_cl_pos+3 - cur_com_pos);
		}
		cout << s << "\n";
		cur_com_pos = s.find(op_com);
	}

	int pos1 = 0, pos2 = s.find("@");
	while ( pos2 != string::npos )
	{
		string cur_str = s.substr(pos1, pos2-pos1);
		if ( pos1 )
			cur_str.erase(0, 1);
		ofs << cur_str << "\n";
		pos1 = pos2;
		pos2 = s.find("@", pos2+1);
	}
	
// #define
	int cur_def = s.find("#define");
	while ( cur_def != string::npos )
	{
		
	}
	
	ifs.close();
	ofs.close();
	
	return 0;
}
