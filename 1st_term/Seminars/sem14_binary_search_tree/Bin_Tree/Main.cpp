// ГЛАВА 12. Пункты 12.1 и 12.3
// ДЕРЕВЬЯ (Двоиные деревья поиска)
#include "Bin_Tree.h"

int main()
{
	srand(time(0));
		
	const int n = 50;
	RandInt rand_int(1, n);
	
	Bin_Tree* tp = 0;
	for (int i = 0; i < n; ++i)
	{
		int key = rand_int();
		if ( !tp->find(key) )
			tp = tp->insert(new Bin_Tree(key));
	}
	
	//PrintKey print_key;
	pre_order_(tp);
	
	return 0;
}
