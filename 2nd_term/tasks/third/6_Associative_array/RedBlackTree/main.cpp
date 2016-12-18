#include "RBTree.h"

using std::cout;

int main()
{
	Map<double, double> tree;
	
	tree.insert(make_pair(100, 100));
	tree.insert(make_pair(50, 50));
	tree.insert(make_pair(150, 150));

//	cout << (tree.begin())->key << " " << (tree.begin())->data << "\n";

	cout << tree.size() << "\n";

	tree.insert(make_pair(200, 200));
	tree.erase(200);

	tree.erase(100);
//	tree.erase(150);
	//tree.erase(50);

	tree.erase(100);

	Map<double, double>::Iterator it1 = tree.find(50);
	cout << (*it1).second << "\n";
	it1 = tree.find(100);
	cout << (*it1).second << "\n";
	it1 = tree.find(150);
	cout << (*it1).second << "\n";

	cout << tree[100] << "\n";

	Map<double, double>::Iterator it2 = tree.begin();
	cout << (*it2).first << "\n";

	cout << (tree.begin())->key << "\n";
	cout << (tree.end())->data << "\n";
	cout << it2->key << " " << it2->data << "\n";

	cout << tree.size() << "\n";

	++it2;
	cout << it2->key << " " << it2->data << "\n";

	for (auto i = tree.begin(); i != nullptr && i != tree.end(); ++i)
		cout << (*i).first << " " << (*i).second << "\n";

	system("PAUSE");

	return 0;
}