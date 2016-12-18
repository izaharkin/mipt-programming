#ifndef _NODE_H

#define _NODE_H

#include <memory>

using std::shared_ptr;

template <class KeyType, class DataType>
class BST;

template <class KeyType, class DataType>
class Node
{
protected:
	typedef shared_ptr< Node<KeyType, DataType> > nodePtr;

	KeyType key;
	DataType data;

	nodePtr left;
	nodePtr right;	
public:
	Node() noexcept
		: key(), data(), left(nullptr), right(nullptr) {}
	Node(const KeyType& _key, const DataType& _data) noexcept
		: key(_key), data(_data), left(nullptr), right(nullptr) {}
	Node(const Node& _node) noexcept
		: key(_node.key), data(_node.data), left(_node.left), right(_node.right) {}
	
	KeyType getKey() const;
	DataType getData() const;

	friend class BST<KeyType, DataType>;
};

template <class KeyType, class DataType>
KeyType Node<KeyType, DataType>::getKey() const
{
	return key;
}

template <class KeyType, class DataType>
DataType Node<KeyType, DataType>::getData() const
{
	return data;
}

#endif /* _NODE_H */
