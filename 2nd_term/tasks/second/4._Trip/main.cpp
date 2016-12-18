#include "Trip.h"

int main()
{
	Graph <int> G;

	G.input();

	if (G.top_sort())
	{
		cout << "There is the order of vertexes (one of possible):\n";
		cout << G.getOrder();
	}
	else
		cout << -1;

	return 0;
}
