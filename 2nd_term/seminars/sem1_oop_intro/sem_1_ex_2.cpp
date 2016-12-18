#include <iostream>
#include <vector>

using namespace std;

class Student
{
private:
	string name;
	vector <int> marks;	
public:
	void set_name (const string& nm)
	{
		name = nm;
	}
	
	void re_mark (int n, int mark)
	{
		marks[n] = mark;
	}
	
	void new_mark (int mark)
	{
		marks.push_back(mark);
	}

	double avg ()
	{
		double avg_mark = 0;
		
		for (int i = 0; i < marks.size(); ++i)
			avg_mark += marks[i];
		avg_mark /= marks.size();
		
		return avg_mark;
	}
};

class Group
{
private:
	vector <Student> gr;
//	int num;
public:
/*	void set_num (int n)
	{
		num = n;
	}
*/	
	void new_st (const Student& st)
	{
		gr.push_back(st);
	}
	
	int q ()
	{
		return gr.size();
	}
	
	double avg ()
	{
		double avg_mark = 0;
		
		for (int i = 0 ; i < gr.size(); ++i)
			avg_mark += gr[i].avg();
		avg_mark /= gr.size();
		
		return avg_mark;
	}
	
	double get_min ()
	{
		int j = 0;
		
		for (int i = 1; i < gr.size(); ++i)
			if ( gr[i].avg() < gr[j].avg() )
				j = i;
				
		return gr[j].avg();
	}
	
	double get_max ()
	{
		int j = 0;
		
		for (int i = 1; i < gr.size(); ++i)
			if ( gr[i].avg() > gr[j].avg() )
				j = i;
				
		return gr[j].avg();
	}
};

class Department
{
private:
	vector <Group> dp;
public:
	void new_gr (const Group& g)
	{
		dp.push_back(g);
	}
	
	double avg ()
	{
		double avg_mark(0);
		int cnt(0);
		
		for (int i = 0 ; i < dp.size(); ++i)
		{
			avg_mark += dp[i].avg() * dp[i].q();
			cnt += dp[i].q();
		}
		avg_mark /= cnt;
		
		return avg_mark;
	}
	
	double get_min ()
	{
		int j = 0;
		
		for (int i = 1; i < dp.size(); ++i)
			if ( dp[i].avg() < dp[j].avg() )
				j = i;
				
		return dp[j].avg();
	}
	
	double get_max ()
	{
		int j = 0;
		
		for (int i = 1; i < dp.size(); ++i)
			if ( dp[i].avg() > dp[j].avg() )
				j = i;
				
		return dp[j].avg();
	}
};

int main()
{
	vector <Student> s(4);
	Group g1, g2;
	Department d1;
	
	for (int i = 0; i < 4; ++i)
	{
		string name;
		
		cin >> name;
		s[i].set_name(name);
		for (int j = 0; j < 4; ++j)
		{
			int m;
			cin >> m;
			s[i].new_mark(m);
		}
		s[i].avg();
	}
	
	for (int i = 0; i < 2; ++i)
		g1.new_st(s[i]);
	cout << g1.avg() << "\n";
	cout << g1.get_max() << "\n";
	
	for (int i = 2; i < 4; ++i)
		g2.new_st(s[i]);
	g2.avg();
	cout << g2.avg() << "\n";
	cout << g2.get_max() << "\n";	
	
	d1.new_gr(g1);
	d1.new_gr(g2);
	
	cout << d1.avg();
	
	return 0;
}
