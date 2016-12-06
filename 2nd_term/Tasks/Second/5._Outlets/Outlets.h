#include <algorithm>
#include <iostream>
#include <assert.h>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

template <class T>
class Graph
{
private:
	vector < vector<T> > g;  // as the list of edges
	vector <char> used;      // visited or not
	vector <int> path;       // path from start vertex to finish vertex
	vector <int> dest;       // destination
	vector <int> p;          // ancestors

	void bfs(const int);
public:
	Graph() : g() {}
	Graph(const vector < vector<T> >& _g)
	{
		g.resize(_g.size());
		for (size_t i = 0; i < g.size(); ++i)
			for (size_t j = 0; j < _g[i].size(); ++j)
				g[i].push_back(_g[i][j]);
	}
	Graph(const Graph& _G) : Graph(_G.g) {}

	void setSize(const int);
	void refresh();          // cleans all containers (except "g"), in order to make them clear for new function 

	vector <int> minPath(const int, const int, int&);

	friend istream& operator >> <> (istream&, Graph<T>&);
};

template <class T>
void Graph<T>::setSize(const int n)
{
	g.resize(n);
}

template <class T>
void Graph<T>::refresh()
{
	used.clear();
	dest.clear();
	p.clear();

	used.resize(g.size(), 0);
	dest.resize(g.size(), 0);
	p.resize(g.size());
}

template <class T>
void Graph<T>::bfs(const int v)
{
//	refresh();
	queue <int> q;
	q.push(v);
	used[v] = true;
	p[v] = -1;

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();
		for (size_t i = 0; i < g[cur].size(); ++i)
		{
			int to = g[cur][i];
			if ( !used[to] )
			{
				used[to] = true;
				dest[to] = dest[cur] + 1;
				p[to] = cur;
				q.push(to);
			}
		}
	}
}

template <class T>
vector <int> Graph<T>::minPath(const int start, const int finish, int& q)
{
	assert(start > 0 && finish <= g.size());
	bfs(start-1);

	if ( !used[finish-1] )
		q = -1;
	else
	{
		q = dest[finish-1];

		for (int v = finish-1; v != -1; v = p[v])
			path.push_back(v);

		reverse(path.begin(), path.end());
	}

	return path;
}

vector<int> parse(const string& s)
{
	vector <int> pars;

	size_t i = 0;
	while (i < s.length())
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			while (i < s.length() && '0' <= s[i] && s[i] <= '9')
			{
				string t = "";
				t += s[i++];
				pars.push_back(atoi(t.c_str()) - 1);
			}
		}
		else
			i++;
	}

	return pars;
}

template <class T>
istream& operator >> (istream& in, Graph<T>& G)
{
	size_t n = G.g.size();
	G.refresh();

	string s;
	getline(in, s);
	for (size_t i = 0; i < n; ++i)
	{
		getline(in, s);
		vector <int> ver = parse(s); // here we are getting vector of <smezny> vertexes, we parse the input
		for (size_t j = 0; j < ver.size(); ++j)
			G.g[i].push_back(ver[j]);
	}

	return in;
}