#include "Outlets.h"

int main()
{
	int n, start, finish;
	Graph <int> G;

	cin >> n;
	cin >> start >> finish;
	G.setSize(n);
	cin >> G;

	int dest;
	vector<int> path = G.minPath(start, finish, dest);

	cout << dest << '\n';
	if (dest > 0)
	{
		for (size_t i = 0; i+1 < path.size(); ++i)
			cout << path[i]+1 << ' ' << path[i+1]+1 << "\n";
	}

	system("PAUSE");

	return 0;
}