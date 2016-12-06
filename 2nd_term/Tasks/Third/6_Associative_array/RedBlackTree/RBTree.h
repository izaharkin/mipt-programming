#ifndef _RBTREE_H_

#define _RBTREE_H_

#include <iostream>
#include <memory>

using std::make_shared;
using std::shared_ptr;
using std::nullptr_t;
using std::make_pair;
using std::iterator;
using std::pair;

enum ColorType { RED, BLACK };

template <class KeyType, class DataType>
struct Node
{
	shared_ptr< Node<KeyType, DataType> > left;
	shared_ptr< Node<KeyType, DataType> > right;
	shared_ptr< Node<KeyType, DataType> > parent;
	ColorType color;
	DataType data;
	KeyType key;
	Node()
		: left(nullptr), right(nullptr), parent(nullptr), color(BLACK), data(), key() {}
	Node(shared_ptr< Node<KeyType, DataType> > _left,
		shared_ptr< Node<KeyType, DataType> >_right,
		shared_ptr< Node<KeyType, DataType> >_parent,
		ColorType _color) : left(_left), right(_right), parent(_parent), color(_color), data(), key() {}
	Node(shared_ptr< Node<KeyType, DataType> > _left,
		shared_ptr< Node<KeyType, DataType> >_right,
		shared_ptr< Node<KeyType, DataType> >_parent,
		ColorType _color,
		DataType _data,
		KeyType _key) : left(_left), right(_right), parent(_parent), color(_color), data(_data), key(_key) {}
	Node(const Node<KeyType, DataType>& _node) 
		: left(_node.left), right(_node.right), parent(_node.parent), color(_node.color), data(_node.data), key(_node.key) {}
};

template <class KeyType, class DataType>
class Map;

template <class KeyType, class DataType>
class RBTree
{
protected:
	//using nodePtr = shared_ptr< Node<KeyType, DataType> >; - somethings is wrong
	shared_ptr< Node<KeyType, DataType> > root;
	size_t rbtSize;

	// basical methods
	shared_ptr< Node<KeyType, DataType> > insert(const KeyType&, const DataType&);
	shared_ptr< Node<KeyType, DataType> > find(const KeyType&) const;
	void erase(const KeyType&);
	// fix balance
	void insertFixBalance(shared_ptr< Node<KeyType, DataType> >&);
	void eraseFixBalance(shared_ptr< Node<KeyType, DataType> >&);
	// rotations
	void rotateRight(shared_ptr< Node<KeyType, DataType> >&);
	void rotateLeft(shared_ptr< Node<KeyType, DataType> >&);
	//  other methods
	shared_ptr< Node<KeyType, DataType> > getGrandparent(const shared_ptr< Node<KeyType, DataType> >&) const;
	shared_ptr< Node<KeyType, DataType> > getSibling(const shared_ptr< Node<KeyType, DataType> >&) const;
	shared_ptr< Node<KeyType, DataType> > getUncle(const shared_ptr< Node<KeyType, DataType> >&) const;
	shared_ptr< Node<KeyType, DataType> > getMin(const shared_ptr< Node<KeyType, DataType> >&) const;
	shared_ptr< Node<KeyType, DataType> > getRoot() const;
	// moving
	shared_ptr< Node<KeyType, DataType> > getNext(const shared_ptr< Node<KeyType, DataType> >&) const;
	shared_ptr< Node<KeyType, DataType> > getPrev(const shared_ptr< Node<KeyType, DataType> >&) const;
	
#define NIL leaf
	shared_ptr< Node<KeyType, DataType> > leaf;
	RBTree() : root(NIL), rbtSize(0), leaf(make_shared< Node<KeyType, DataType> >(NIL, NIL, nullptr, BLACK)) {}
	DataType& operator [](const KeyType&) const;
	size_t size() const;
public:
	class Iterator: public iterator<std::bidirectional_iterator_tag, shared_ptr< Node<KeyType, DataType> > >
	{
	private:
		friend class Map<KeyType, DataType>::Iterator;
		shared_ptr< RBTree<KeyType, DataType> > treePtr;
		shared_ptr< Node<KeyType, DataType> > nodePtr;
	public:
		Iterator() : treePtr(nullptr), nodePtr(nullptr) {}
		Iterator(shared_ptr< RBTree<KeyType, DataType> > _treePtr, shared_ptr< Node<KeyType, DataType> > _nodePtr)
		{
			treePtr = _treePtr;
			nodePtr = _nodePtr;
		}

		pair<KeyType, DataType> operator * () const
		{
			return make_pair(nodePtr->key, nodePtr->data);
		}

		shared_ptr< Node<KeyType, DataType> > operator -> () const
		{
			return nodePtr;
		}

		Iterator operator ++ ()
		{
			nodePtr = treePtr->getNext(nodePtr);
			return *this;
		}

		Iterator operator -- ()
		{
			nodePtr = treePtr->getPrev(nodePtr);
			return *this;
		}

		bool operator != (const nullptr_t& null) const
		{
			return !(treePtr == null || nodePtr == null);
		}
		bool operator == (const Iterator& toCompare) const
		{
			return (treePtr == toCompare.treePtr && nodePtr->key == toCompare.nodePtr->key && nodePtr->data == toCompare.nodePtr->data);
		}
		bool operator != (const Iterator& toCompare) const
		{
			return !(*this == toCompare);
		}
		bool operator < (const Iterator& toCompare) const
		{
			return (treePtr == toCompare.treePtr && nodePtr->key < toCompare.nodePtr->key);
		}
		bool operator > (const Iterator& toCompare) const
		{
			return !(this < toCompare || this == toCompare);
		}
		bool operator >= (const Iterator& toCompare) const
		{
			return !(this < toCompare);
		}
		bool operator <= (const Iterator& toCompare) const
		{
			return (this < toCompare || this == toCompare);
		}
	};

	Iterator begin() const
	{
		shared_ptr< Node<KeyType, DataType> > beginFind = root;

		while (beginFind->left != NIL)
			beginFind = beginFind->left;

		Iterator it(make_shared< RBTree<KeyType, DataType> >(*this), beginFind);
		return it;
	}

	Iterator end() const
	{
		shared_ptr< Node<KeyType, DataType> > endFind = root;

		while (endFind->right != NIL)
			endFind = endFind->right;

		Iterator it(make_shared< RBTree<KeyType, DataType> >(*this), endFind->right);
		return it;
	}

	friend Map<KeyType, DataType>;
};

template <class KeyType, class DataType>
class Map
{
private:
	RBTree<KeyType, DataType> rbtree;
public:
	class Iterator : public RBTree<KeyType, DataType>::Iterator
	{
	private:
		shared_ptr< RBTree<KeyType, DataType> > treePtr;
		shared_ptr< Node<KeyType, DataType> > nodePtr;
	public:
		Iterator() : treePtr(nullptr), nodePtr(nullptr) {}
		Iterator(typename RBTree<KeyType, DataType>::Iterator rbIter)
			: treePtr(rbIter.treePtr), nodePtr(rbIter.nodePtr) {}
		Iterator(shared_ptr< RBTree<KeyType, DataType> > _treePtr, shared_ptr< Node<KeyType, DataType> > _nodePtr)
		{
			treePtr = _treePtr;
			nodePtr = _nodePtr;
		}
		pair<KeyType, DataType> operator * () const
		{
			return make_pair(nodePtr->key, nodePtr->data);
		}

		shared_ptr< Node<KeyType, DataType> > operator -> () const
		{
			return nodePtr;
		}

		Iterator operator ++ ()
		{
			nodePtr = treePtr->getNext(nodePtr);
			return *this;
		}

		Iterator operator -- ()
		{
			nodePtr = treePtr->getPrev(nodePtr);
			return *this;
		}

		bool operator != (const nullptr_t& null) const
		{
			return !(treePtr == null || nodePtr == null);
		}
		bool operator == (const Iterator& toCompare) const
		{
			return (treePtr == toCompare.treePtr && nodePtr->key == toCompare.nodePtr->key && nodePtr->data == toCompare.nodePtr->data);
		}
		bool operator != (const Iterator& toCompare) const
		{
			return !(*this == toCompare);
		}
		bool operator < (const Iterator& toCompare) const
		{
			return (treePtr == toCompare.treePtr && nodePtr->key < toCompare.nodePtr->key);
		}
		bool operator >(const Iterator& toCompare) const
		{
			return !(this < toCompare || this == toCompare);
		}
		bool operator >= (const Iterator& toCompare) const
		{
			return !(this < toCompare);
		}
		bool operator <= (const Iterator& toCompare) const
		{
			return (this < toCompare || this == toCompare);
		}
	};

	Iterator insert(const pair<KeyType, DataType>& nodeToInsert)
	{
		Iterator inserted(make_shared< RBTree<KeyType, DataType> >(rbtree), rbtree.insert(nodeToInsert.first, nodeToInsert.second));
		return inserted;
	}

	Iterator find(const KeyType& keyToFind) const
	{
		Iterator founded(make_shared< RBTree<KeyType, DataType> >(rbtree), rbtree.find(keyToFind));
		return founded;
	}

	void erase(const KeyType& keyToErase)
	{
		rbtree.erase(keyToErase);
	}

	Iterator begin() const
	{
		return Iterator(rbtree.begin());
	}

	Iterator end() const
	{
		return Iterator(rbtree.end());
	}

	DataType& operator [](const KeyType&) const;
	size_t size() const;
};

// RED-BLACK TREE

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > RBTree<KeyType, DataType>::
	getGrandparent(const shared_ptr< Node<KeyType, DataType> >& curNode) const
{
	if ((curNode != nullptr) && (curNode->parent != nullptr))
		return curNode->parent->parent;
	else
		return nullptr;  // No parent means no granparent
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > RBTree<KeyType, DataType>::
	getUncle(const shared_ptr< Node<KeyType, DataType> >& curNode) const
{
	shared_ptr< Node<KeyType, DataType> > grandparent = getGrandparent(curNode);
	if (grandparent == nullptr)
		return nullptr;  // No grandparent means no uncle
	if (curNode->parent == grandparent->left)
		return grandparent->right;
	else
		return grandparent->left;
}

template <class KeyType, class DataType>
void RBTree<KeyType, DataType>::
	rotateLeft(shared_ptr< Node<KeyType, DataType> >& curNode)
{
	shared_ptr< Node<KeyType, DataType> > curNodeChild = curNode->right;

	curNode->right = curNodeChild->left;
	if (curNodeChild->left != NIL)
		curNodeChild->left->parent = curNode;

	if (curNodeChild != NIL)
		curNodeChild->parent = curNode->parent;
	if (curNode->parent)
	{
		if (curNode == curNode->parent->left)
			curNode->parent->left = curNodeChild;
		else
			curNode->parent->right = curNodeChild;
	}
	else
		root = curNodeChild;

	curNodeChild->left = curNode;
	if (curNode != NIL)
		curNode->parent = curNodeChild;
}

template <class KeyType, class DataType>
void RBTree<KeyType, DataType>::
	rotateRight(shared_ptr< Node<KeyType, DataType> >& curNode)
{
	shared_ptr< Node<KeyType, DataType> > curNodeChild = curNode->left;

	curNode->left = curNodeChild->right;
	if (curNodeChild->right != NIL) 
		curNodeChild->right->parent = curNode;

	if (curNodeChild != NIL) 
		curNodeChild->parent = curNode->parent;
	if (curNode->parent)
	{
		if (curNode == curNode->parent->right)
			curNode->parent->right = curNodeChild;
		else
			curNode->parent->left = curNodeChild;
	}
	else
		root = curNodeChild;

	curNodeChild->right = curNode;
	if (curNode != NIL) 
		curNode->parent = curNodeChild;
}

template <class KeyType, class DataType>
size_t RBTree<KeyType, DataType>::
	size() const
{
	return rbtSize;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > RBTree<KeyType, DataType>::
	getRoot() const
{
	return root;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > RBTree<KeyType, DataType>::
	find(const KeyType& newKey) const
{
	shared_ptr< Node<KeyType, DataType> > curNode = root;

	while (curNode != NIL)
		if (newKey == curNode->key)
			return curNode;
		else
			curNode = newKey < curNode->key ? curNode->left : curNode->right;

	return NIL;
}

template <class KeyType, class DataType>
void RBTree<KeyType, DataType>::
	insertFixBalance(shared_ptr< Node<KeyType, DataType> >& newNode)
{
	while (newNode != root && newNode->parent->color == RED)  // while we have a voilation of balance
	{
		// parent is RED (otherwise we already inserted out newNode)
		shared_ptr< Node<KeyType, DataType> > grandparent = getGrandparent(newNode);
		shared_ptr< Node<KeyType, DataType> > uncle = getUncle(newNode);
		if (uncle->color == RED) // case 1: uncle is RED
		{
			newNode->parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color = RED;
			newNode = grandparent;
		}
		else  // case 2: uncle is BLACK
		{
			if (newNode->parent == grandparent->left)  // parent is the left child of grandparent
			{
				if (newNode == newNode->parent->right)
				{
					newNode = newNode->parent;
					rotateLeft(newNode);
				}
				newNode->parent->color = BLACK;
				grandparent->color = RED;
				rotateRight(grandparent);  // right rotation of grandparent (now grandpa is BLACK, parent is RED and uncle is RED)
			}
			else // parent is the right child of grandparent
			{
				if (newNode == newNode->parent->left)
				{
					newNode = newNode->parent;
					rotateRight(newNode);
				}
				newNode->parent->color = BLACK;
				grandparent->color = RED;
				rotateLeft(grandparent); // left rotation of grandparent (now grandpa is BLACK, parent is RED and uncle is RED)
			}
		}
	}

	root->color = BLACK;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > RBTree<KeyType, DataType>::
	insert(const KeyType& newKey, const DataType& newData) 
{
	shared_ptr< Node<KeyType, DataType> > current, parent, newNode(make_shared< Node<KeyType, DataType> >(NIL, NIL, nullptr, RED, newData, newKey));

	current = root;
	parent = nullptr;
	while (current != NIL && current != nullptr) 
	{
		if (newKey == current->key) 
			return current;
		parent = current;
		current = (newKey < current->key ? current->left : current->right);
	}
	newNode->parent = parent;

	if (parent) 
	{
		if (newKey < parent->key)
			parent->left = newNode;
		else
			parent->right = newNode;
	}
	else 
		root = newNode;

	insertFixBalance(newNode);

	rbtSize++;
	return newNode;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > RBTree<KeyType, DataType>::
	getSibling(const shared_ptr< Node<KeyType, DataType> >& curNode) const
{
	if (curNode == curNode->parent->left)
		return curNode->parent->right;
	else
		return curNode->parent->left;
}

template <class KeyType, class DataType>
void RBTree<KeyType, DataType>::
	eraseFixBalance(shared_ptr< Node<KeyType, DataType> >& toDel)
{
	while (toDel != root && toDel->color == BLACK)
	{
		shared_ptr< Node<KeyType, DataType> > sibling = getSibling(toDel); // sibling is right
		if (toDel == toDel->parent->left) // if it is a left child
		{
			if (sibling->color == RED)          // case 1: sibling is RED
			{
				sibling->color = BLACK;
				toDel->parent->color = RED;
				rotateLeft(toDel->parent);
				sibling = toDel->parent->right;
			}
			if (sibling->left->color == BLACK && sibling->right->color == BLACK) // case 2: sibling is BLACK, both sibling`s sons are BLACK
			{
				sibling->color = RED;
				toDel = toDel->parent;
			}
			else
			{
				if (sibling->right->color == BLACK) // case 3: sibling is BLACK, right sibling`s son is BLACK
				{
					sibling->left->color = BLACK;
					sibling->color = RED;
					rotateRight(sibling);
					sibling = toDel->parent->right;
				}
				sibling->color = toDel->parent->color;
				toDel->parent->color = BLACK;
				sibling->right->color = BLACK;
				rotateLeft(toDel->parent);
				toDel = root;
			}
		}
		else // if it is a right child
		{
			if (sibling->color == RED) // case 1: sibling is RED
			{
				sibling->color = BLACK;
				toDel->parent->color = RED;
				rotateRight(toDel->parent);
				sibling = toDel->parent->left;
			}
			if (sibling->right->color == BLACK && sibling->left->color == BLACK) // case 2: sibling is BLACK, both sibling`s sons are BLACK
			{
				sibling->color = RED;
				toDel = toDel->parent;
			}
			else
			{
				if (sibling->left->color == BLACK) // case 3: sibling is BLACK, right sibling`s son is BLACK
				{
					sibling->right->color = BLACK;
					sibling->color = RED;
					rotateLeft(sibling);
					sibling = toDel->parent->left;
				}
				sibling->color = toDel->parent->color;
				toDel->parent->color = BLACK;
				sibling->left->color = BLACK;
				rotateRight(toDel->parent);
				toDel = root;
			}
		}
	}
	toDel->color = BLACK;
}

template <class KeyType, class DataType>
void RBTree<KeyType, DataType>::
	erase(const KeyType& delKey)
{
	shared_ptr< Node<KeyType, DataType> > toDelete = find(delKey);

	if (toDelete == nullptr || toDelete == NIL) // there is no node with this key
		return;

	shared_ptr< Node<KeyType, DataType> > sonDel, curDel;
	if (toDelete->left == NIL || toDelete->right == NIL) // if less than 2 childs
		curDel = toDelete;
	else
	{
		curDel = toDelete->right;
		while (curDel->left != NIL)
			curDel = curDel->left;
	}
	if (curDel->left != NIL)
		sonDel = curDel->left;
	else 
		sonDel = curDel->right;

	sonDel->parent = curDel->parent;
	if (curDel->parent != nullptr)
	{
		if (curDel == curDel->parent->left)
			curDel->parent->left = sonDel;
		else 
			curDel->parent->right = sonDel;
	}
	else 
		root = sonDel; // if curDel is root

	if (curDel != toDelete)
	{
		toDelete->key = curDel->key;
		toDelete->data = curDel->data;
	}
	if (curDel->color == BLACK)
		eraseFixBalance(sonDel);

	curDel.reset();

	rbtSize--;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > RBTree<KeyType, DataType>::
	getNext(const shared_ptr< Node<KeyType, DataType> >& curNode) const
{
	shared_ptr< Node<KeyType, DataType> > nextNode = curNode;

	if (nextNode->right != NIL)
	{
		nextNode = nextNode->right;
		while (nextNode->left != NIL)
			nextNode = nextNode->left;
		return nextNode;
	}
	else
	{
		while (nextNode->parent != nullptr)
		{
			if (nextNode == nextNode->parent->left)
				return nextNode->parent;
			else
				nextNode = nextNode->parent;
		}
	}

	return nullptr;
}

template <class KeyType, class DataType>
shared_ptr< Node<KeyType, DataType> > RBTree<KeyType, DataType>::
	getPrev(const shared_ptr< Node<KeyType, DataType> >& curNode) const
{
	shared_ptr< Node<KeyType, DataType> > prevNode = curNode;

	if (prevNode->left != NIL)
	{
		prevNode = prevNode->left;
		while (prevNode->right != NIL)
			prevNode = prevNode->right;
		return prevNode;
	}
	else
	while (prevNode->parent != nullptr)
	{
		if (prevNode == prevNode->parent->right)
			return prevNode->parent;
		else
			prevNode = prevNode->parent;
	}

	return nullptr;
}

template <class KeyType, class DataType>
DataType& RBTree<KeyType, DataType>::operator [](const KeyType& keyToFind) const
{
	shared_ptr< Node<KeyType, DataType> > curNode = root;

	while (true)
	{
		if (curNode == NIL || curNode == nullptr) 
		{
			return NIL->data;
		}
		if (curNode->key == keyToFind)
			return curNode->data;
		if (keyToFind < curNode->key)
			curNode = curNode->left;
		else 
			curNode = curNode->right;
	}
}

// MAP

template <class KeyType, class DataType>
DataType& Map<KeyType, DataType>::
	operator [](const KeyType& keyToFind) const
{
		return rbtree[keyToFind];
}

template <class KeyType, class DataType>
size_t Map<KeyType, DataType>::
	size() const
{
		return rbtree.size();
}

#endif