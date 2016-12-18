#include <algorithm>
#include <iostream>
#include <assert.h>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

template <class T>
class Graph
{
private:
	vector < vector<T> > g;  // as the list of edges
	vector <char> color;     // white, grey or black
	vector <char> used;      // visited or not
	vector <int> order;      // topological order
	vector <int> p;          // ancestors

	void dfs(const int);
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

	int size() const;

	bool cyclic(const int);
	bool top_sort();
	vector <int> getOrder() const;
	
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
	
	void input()
	{
		size_t n;
		cin >> n;
	
		(*this).g.resize(n);
		(*this).p.resize(n);
		(*this).color.resize(n, 0);
		(*this).used.resize(n, 0);

		string s;
		getline(cin, s);
		for (size_t i = 0; i < n; ++i)
		{
			getline(cin, s);
			vector <int> ver = parse(s); // here we are getting vector of <smezny> vertexes, we parse the input
			for (size_t j = 0; j < ver.size(); ++j)
			{
				if (ver[j] < 0)
				{
					cout << -1;
					assert(0);
				}
				(*this).g[i].push_back(ver[j]);
			}
		}
	}

/*
	istream& operator >> (istream& in, Graph<T>& G)
	{
		size_t n;
		in >> n;
	
		G.g.resize(n);
		G.p.resize(n);
		G.color.resize(n, 0);
		G.used.resize(n, 0);
	
		string s;
		getline(in, s);
		for (size_t i = 0; i < n; ++i)
		{
			getline(in, s);
			vector <int> ver = parse(s); // here we are getting vector of <smezny> vertexes, we parse the input
			for (size_t j = 0; j < ver.size(); ++j)
			{
				if (ver[j] < 0)
				{
					cout << -1;
					assert(0);
				}
				G.g[i].push_back(ver[j]);
			}
		}
	
		return in;
	}*/
};

template <class T>
int Graph<T>::size() const
{
	return g.size();
}

template <class T>
vector<int> Graph<T>::getOrder() const
{
	return order;
}

template <class T>
void Graph<T>::dfs(const int curVer)
{
	used[curVer] = true;
	for (size_t i = 0; i < g[curVer].size(); ++i)
	{
		int next = g[curVer][i];
		if (used[next] == 0)
			dfs(next);
	}
	order.push_back(curVer);
}

template <class T>
bool Graph<T>::cyclic(const int curVer)
{
	color[curVer] = 1;

	for (size_t i = 0; i < g[curVer].size(); ++i)
	{
		int next = g[curVer][i];
		if (color[next] == 0)
		{
			p[next] = curVer;
			if (cyclic(next)) 
				return true;
		}
		else if (color[next] == 1) 
			return true;
	}

	color[curVer] = 2;

	return false;
}

template <class T>
bool Graph<T>::top_sort()
{
	int n = g.size();

	bool flag = true;

	for (int i = 0; i < n; i++)
		if ( cyclic(i) )
			flag = false;

	for (int i = 0; i < n; i++)
		if (color[i] != 2)
			flag = false;

	for (int i = 0; i < n; ++i)
		if ( !used[i] )
			dfs(i);

	return flag;
}
/*
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
}*/
/*
template <class T>
istream& operator >> (istream& in, Graph<T>& G)
{
	size_t n;
	in >> n;

	G.g.resize(n);
	G.p.resize(n);
	G.color.resize(n, 0);
	G.used.resize(n, 0);

	string s;
	getline(in, s);
	for (size_t i = 0; i < n; ++i)
	{
		getline(in, s);
		vector <int> ver = parse(s); // here we are getting vector of <smezny> vertexes, we parse the input
		for (size_t j = 0; j < ver.size(); ++j)
		{
			if (ver[j] < 0)
			{
				cout << -1;
				assert(0);
			}
			G.g[i].push_back(ver[j]);
		}
	}

	return in;
}
*/
template <class T>
ostream& operator << (ostream& out, const vector<T>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
			out << v[i] << " ";
	out << "\n";
	return out;
}
