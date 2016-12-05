#include <iostream>
#include "binary_tree.h"

using namespace std;

int max_depth (Bin_Tree *tp)
{
	if ( !tp ) return 0;
	return 1 + max(max_depth(tp->left), max_depth(tp->right));
}

int min_depth (Bin_Tree *tp)
{
	if ( !tp ) return 0;
	return 1 + min(min_depth(tp->left), min_depth(tp->right));
}

bool check_tree (Bin_Tree *tp)
{
	if ( !tp ) return 0;
	return !(max_depth(tree) - min_depth(tree) > 1);
}

int main()
{
	
	
	return 0;
}
