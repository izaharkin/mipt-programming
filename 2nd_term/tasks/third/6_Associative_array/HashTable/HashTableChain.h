#ifndef _HASHTABLE_CHAIN_H_

#define _HASHTABLE_CHAIN_H_

#define LARGE_PRIME 26227
#define STARTING_CAPACITY 3

#include <functional>
#include <iostream>
#include <vector>
#include <memory>

using std::make_shared;
using std::shared_ptr;
using std::nullptr_t;
using std::make_pair;
using std::vector;
using std::hash;
using std::pair;
using std::cout;

template<class KeyType, class DataType>
class HashTableWithCnains
{
private:
	struct Slot
	{
		vector<pair<KeyType, DataType>> slot;
		Slot() : slot() {}
	};

	vector<Slot> table;
	shared_ptr<vector<Slot>> tablePtr;
	size_t tableSize;
	size_t tableCapacity;

	size_t hashFunction(KeyType key) const
	{
		return hash<KeyType>()(key) * LARGE_PRIME % tableCapacity;
	}
	void capacityIncrease();
public:
	HashTableWithCnains() : tableSize(0), tableCapacity(STARTING_CAPACITY)
	{
		table.resize(STARTING_CAPACITY);
		tablePtr = make_shared<vector<Slot>>(table);
	}

	class HashTableIterator
	{
	private:
		typename vector<pair<KeyType, DataType>>::iterator iter;
		typename shared_ptr<vector<Slot>> tablePtr;
	public:
		HashTableIterator(nullptr_t null) 
			: iter(null), tablePtr(null) {}

		HashTableIterator(const HashTableIterator& newIter) 
			: iter(newIter.iter), tablePtr(newIter.tablePtr) {}

		HashTableIterator(const typename vector<pair<KeyType, DataType>>::iterator newIter, const typename shared_ptr<vector<Slot>> newTablePtr)
			: iter(newIter), tablePtr(newTablePtr) {}
	
		HashTableIterator& operator = (const HashTableIterator& newIter)
		{
			iter = newIter.iter;
			tablePtr = newIter.tablePtr;
			return *this;
		}

		HashTableIterator& operator ++ ()
		{
			++iter;
			while (iter != (*tablePtr).end() && (iter->size() == 0))
				++iter;
			return *this;
		}

		HashTableIterator& operator -- ()
		{
			--iter;
			while (iter != (tablePtr->table.begin() - 1) && (iter->size() == 0))
				--iter;
			return *this;
		}

		typename vector<pair<KeyType, DataType>>::iterator operator * ()
		{
			return iter;
		}

		bool operator != (const HashTableIterator& secondIter)
		{
			return (iter != secondIter.iter || tablePtr != secondIter.tablePtr);
		}

		bool operator == (const HashTableIterator& secondIter)
		{
			return iter == secondIter.iter && tablePtr == secondIter.tablePtr;
		}
	};
	typedef HashTableIterator iterator;

	iterator begin()
	{
		iterator iter(table.begin(), tablePtr);
		return iter;
	}

	iterator end()
	{
		iterator iter(table.end(), tablePtr);
		return iter;
	}

	iterator insert(const KeyType& key, const DataType& data);
	iterator find(const KeyType& keyToFind);
	void erase(const KeyType& delKey);

	DataType& operator [] (const KeyType& keyToFind)
	{
		auto iter = find(keyToFind);
		return (*iter).data;
	}
};

template<class KeyType, class DataType>
void HashTableWithCnains<KeyType, DataType>::
	capacityIncrease()
{
	vector<Slot> dumpTable;
	dumpTable.resize(tableCapacity);
	dumpTable = table;

	for (size_t index = 0; index < tableSize; ++index)
		table[index].slot.clear();
	table.clear();

	table.resize(tableCapacity * 2);
	tableCapacity *= 2;
	for (size_t i = 0; i < dumpTable.size(); ++i)
		for (size_t j = 0; j < dumpTable[i].slot.size(); ++j)
			insert(dumpTable[i].slot[j].first, dumpTable[i].slot[j].second);
}

template<class KeyType, class DataType>
typename HashTableWithCnains<KeyType, DataType>::iterator HashTableWithCnains<KeyType, DataType>::
	insert(const KeyType& key, const DataType& data)
{
	size_t curPosition = hashFunction(key);

	for (typename vector<pair<KeyType, DataType>>::iterator curListIterator = table[curPosition].slot.begin(); curListIterator != table[curPosition].slot.end(); ++curListIterator)
		if (curListIterator->first == key)
			return iterator(curListIterator, tablePtr);

	table[curPosition].slot.push_back(make_pair(key, data));
	tableSize++;
	
	if (table[curPosition].slot.size() > tableSize)
	{
		capacityIncrease();
		return insert(key, data);
	}

	return iterator(table[curPosition].slot.end() - 1, tablePtr);
}

template<class KeyType, class DataType>
typename HashTableWithCnains<KeyType, DataType>::iterator HashTableWithCnains<KeyType, DataType>::
	find(const KeyType& keyToFind)
{
	size_t curPosition = hashFunction(keyToFind);

	typename vector<pair<KeyType, DataType>>::iterator curListIterator = table[curPosition].slot.begin();
	while (curListIterator != table[curPosition].slot.end() && curListIterator->first != keyToFind)
		++curListIterator;

	if (curListIterator == table[curPosition].slot.end())
		return nullptr;
	else
		return iterator(curListIterator, tablePtr);
}

template<class KeyType, class DataType>
void HashTableWithCnains<KeyType, DataType>::
	erase(const KeyType& delKey)
{
	size_t curPosition = hashFunction(delKey);

	auto index = table[curPosition].slot.begin();
	for (index = table[curPosition].slot.begin(); index != table[curPosition].slot.end(); ++index)
		if (index->first == delKey)
			break;

	if (index != table[curPosition].slot.end())
	{
		table[curPosition].slot.erase(index);
		tableSize--;
	}
}

#endif /*_HASHTABLE_CHAIN_H_*/