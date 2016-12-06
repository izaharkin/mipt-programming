#ifndef _BST_H

#define _BST_H

#include <iostream>
#include <vector>
#include "Node.h"

using std::make_shared;
using std::shared_ptr;
using std::cout;

template <class KeyType, class DataType>
class BST
{
protected:
	typedef shared_ptr< Node<KeyType, DataType> > nodePtr;

	nodePtr bstRoot;

	nodePtr find(const nodePtr&, const KeyType&) const;
	void insert(nodePtr&, const KeyType&, const DataType&);	
	void erase(nodePtr&, const KeyType&);
public:
	// constructors
	BST() noexcept
		: bstRoot(nullptr) {}
	BST(const nodePtr& _bstRoot) noexcept
		: bstRoot(_bstRoot) {}
	BST(const BST& _bst) noexcept // copy
		: bstRoot(_bst.bstRoot) {}
	// basic methods
	nodePtr find(const KeyType&) const;
	void insert(const KeyType&, const DataType&);	
	void erase(const KeyType&);
	void clear(nodePtr&);
	// additional methods	
	nodePtr& getRoot();
	nodePtr getMin(const nodePtr&);
	nodePtr getMax(const nodePtr&);	
//	size_t height() const;
	bool isEmpty(const nodePtr&) const;
	size_t size(const nodePtr&) const;
	// orders
	void preOrder(nodePtr, void (*)(const nodePtr&));
	void inOrder(nodePtr, void (*)(const nodePtr&));
	void postOrder(nodePtr, void (*)(const nodePtr&));
	// destructor
	~BST() noexcept
	{ 
		clear(bstRoot); 
	}
};

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > BST<KeyType, DataType>::
	find(const nodePtr& curRoot, const KeyType& newKey) const
{
	if ( curRoot != nullptr )
	{
		if ( newKey < curRoot->key )
		{
			if (curRoot->left == nullptr || curRoot->left->key < newKey)
				return curRoot;
			else
				 find(curRoot->left, newKey);
		}
		else if ( newKey > curRoot->key )
		{
			if (curRoot->right != nullptr)
				find(curRoot->right, newKey);
			else
				return curRoot;
		}
		else
			return curRoot;
	}
	else
		return nullptr;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > BST<KeyType, DataType>::
	find(const KeyType& newKey) const
{
	return find(bstRoot, newKey);
}

template <class KeyType, class DataType>
void BST<KeyType, DataType>::
	insert(nodePtr& curRoot, const KeyType& newKey, const DataType& newData)
{
	if ( curRoot == nullptr )
		curRoot = make_shared< Node<KeyType, DataType> > (newKey, newData);	
	else if ( newKey < curRoot->key )
		insert(curRoot->left, newKey, newData);
	else /*if (newKey >= curRoot->key )*/
		insert(curRoot->right, newKey, newData);		
}

template <class KeyType, class DataType>
void BST<KeyType, DataType>::
	insert(const KeyType& newKey, const DataType& newData)
{
	return insert(bstRoot, newKey, newData);
}

template <class KeyType, class DataType>
void BST<KeyType, DataType>::
	erase(nodePtr& curRoot, const KeyType& delKey)
{
	if ( isEmpty(curRoot) )
		return;
	else
	{
		if ( delKey < curRoot->key )
			return erase(curRoot->left, delKey);
		else if ( delKey > curRoot->key )
			return erase(curRoot->right, delKey);
		else
		{
			if ( curRoot->left == nullptr )
			{
				if ( curRoot->right == nullptr )
				{
					curRoot.reset();
				}
				else
				{
					curRoot->key = (curRoot->right)->key;
					curRoot->data = (curRoot->right)->data;
					erase(curRoot->right, (curRoot->right)->key);
				}
			}
			else if ( curRoot->right == nullptr )
			{
				curRoot->key = (curRoot->left)->key;
				curRoot->data = (curRoot->left)->data;
				erase(curRoot->left, (curRoot->left)->key);
			}
			else
			{
				nodePtr instead = getMin(curRoot->right);
				curRoot->key = instead->key;				
				curRoot->data = instead->data;				
				erase(curRoot->right, instead->key);
			}
		}	
	}
}

template <class KeyType, class DataType>
void BST<KeyType, DataType>::
	erase(const KeyType& delKey)
{
	return erase(bstRoot, delKey);
}

template <class KeyType, class DataType>
void BST<KeyType, DataType>::
	clear(nodePtr& curRoot)
{
	
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> >& BST<KeyType, DataType>::
	getRoot()
{
	return bstRoot;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > BST<KeyType, DataType>::
	getMin(const nodePtr& curRoot)
{
	nodePtr minNode(curRoot);
	while ( minNode->left )
		minNode = minNode->left;
	return minNode;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > BST<KeyType, DataType>::
	getMax(const nodePtr& curRoot)
{
	nodePtr maxNode(curRoot);
	while ( maxNode->right )
		maxNode = maxNode->right;
	return maxNode;
}

template <class KeyType, class DataType>
bool BST<KeyType, DataType>::
	isEmpty(const nodePtr& curRoot) const
{
	return (curRoot == nullptr);
}

template <class KeyType, class DataType>
size_t BST<KeyType, DataType>::
	size(const nodePtr& curRoot) const
{
	if ( curRoot == nullptr )
		return 0;
	else
		return (1 + size(curRoot->left) + size(curRoot->right));
}

template <class KeyType, class DataType>
void BST<KeyType, DataType>::
	postOrder(nodePtr curRoot, void (*func)(const nodePtr&))
{
	if ( curRoot )
	{
		postOrder(curRoot->left, func);
		postOrder(curRoot->right, func);		
		func(curRoot);
	}
}

template <class KeyType, class DataType>
void BST<KeyType, DataType>::
	preOrder(nodePtr curRoot, void (*func)(const nodePtr&))
{
	if ( curRoot )
	{
		func(curRoot);
		preOrder(curRoot->left, func);
		preOrder(curRoot->right, func);
	}
}

template <class KeyType, class DataType>
void BST<KeyType, DataType>::
	inOrder(nodePtr curRoot, void (*func)(const nodePtr&))
{
	if ( curRoot )
	{
		inOrder(curRoot->left, func);
		func(curRoot);
		inOrder(curRoot->right, func);
	}
}

// OTHER FUNCTIONS

template <class KeyType, class DataType>
void print(const shared_ptr< Node<KeyType, DataType> >& cur)
{
	cout << cur->getKey() << " " << cur->getData() << "\n";
}

#endif /* _BST_H */
