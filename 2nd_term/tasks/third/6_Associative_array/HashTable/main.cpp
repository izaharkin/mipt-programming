#include "HashTableChain.h"

int main()
{
	HashTableWithCnains<int, int> hashTable;

	hashTable.insert(1, 1);
	hashTable.insert(2, 2);
	hashTable.insert(3, 3);
	hashTable.insert(4, 4);
	hashTable.insert(5, 5);
	hashTable.insert(1276, 444);

	hashTable.erase(2);
	hashTable.erase(6);

	std::cout << "\n" << (*hashTable.find(1267))->second;

	system("PAUSE");

	return 0;
}