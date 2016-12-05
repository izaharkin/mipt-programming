#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;

struct Index
{
	int i, j;
	Index () : i(-1), j(-1) {}
	Index (int ii, int jj) : i(ii), j(jj) {}
};

struct Cell
{
	char color;
	bool visited;
	Index comes_from;
};

typedef vector < vector<Cell> > Field;

Field read (const string& filename)
{
	ifstream ifs(filename.c_str());
	Field field;
	char x;
	
	ifs >> n >> m;
	field.resize(n);
	for (int i = 0; i < n; i++)
	{
		field[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			ifs >> x;
			field[i][j].color = x;
			field[i][j].visited = (x != '.');
		}
	}
	
	return field;
}

Index get_neighbour (Index pos, int dir)
{
	switch ( dir )
	{
		case 1:{
			return Index(pos.i-1, pos.j);
		}
		case 2:{
			return Index(pos.i, pos.j+1);
		}
		case 3:{
			return Index(pos.i+1, pos.j);
		}
		case 4:{
			return Index(pos.i, pos.j-1);
		}
	}
	
	return Index();
}

bool wave_pass (Field& field, Index entry, Index exit)
{
	queue <Index> q;
	
	q.push(entry);
	field[entry.i][entry.j].color = '.';
	field[entry.i][entry.j].visited = true;
	field[entry.i][entry.j].comes_from = Index(-1, -1);
	
	while ( !q.empty() )
	{
		Index cur = q.front();
		q.pop();
		
		for (int i = 1; i <= 4; i++)
		{
			Index t = get_neighbour(cur, i);
			
			if ( t.i < 0 || t.i >= n || t.j < 0 || t.j >= m )
				continue;
				
			if ( !field[t.i][t.j].visited )
			{
				field[t.i][t.j].color = '.';
				field[t.i][t.j].visited = true;
				field[t.i][t.j].comes_from = cur;
				q.push(t);
			}
		}
		
		field[cur.i][cur.j].color = '.';
		
		if ( cur.i == exit.i && cur.j == exit.j )
			return true;
	} 

	return false;
}

void print_f (const Field& field)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << field[i][j].color;
		cout << "\n";
	}
}

stack <Index> get_path (Field& field, Index exit)
{
	Index cur = exit;
	stack <Index> path;
	
	while ( cur.i != -1 && cur.j != -1  )
	{
		path.push(cur);
		field[cur.i][cur.j].color = '*';
		cur = field[cur.i][cur.j].comes_from;
	}
	
	print_f(field);
	
	return path;
}

int main()
{
	Field field = read("labyrinth.in.txt");
	Index entry(0, 0);
	Index exit(field.size()-1, field[0].size()-1);
	
	if ( wave_pass(field, entry, exit) )
	{
		stack <Index> path = get_path(field, exit);
		while ( !path.empty() )
		{
			cout << "(" << path.top().i << ", " << path.top().j << ")" 
				 << (path.size() > 1 ? " -> " : "\n");
			path.pop();
		}
	}
	else
		cout << "No path!\n";
	
	return 0;
}
