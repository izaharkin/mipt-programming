//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E1_TREAP_HEIGHT_TREAP_H
#define E1_TREAP_HEIGHT_TREAP_H

#include <memory>

using std::make_shared;
using std::shared_ptr;

// ValueType is not used in this task
template<typename KeyType, typename PType, typename ValueType>
class TreapNode {
 public:
  KeyType key_;
  PType priority_;
  ValueType value_; // is not used in this task
  shared_ptr<TreapNode> left_;
  shared_ptr<TreapNode> right_;
  TreapNode() = default;
  ~TreapNode() = default;
  TreapNode(KeyType key, PType priority);
};

template<typename KeyType, typename PType, typename ValueType>
TreapNode<KeyType, PType, ValueType>::TreapNode(KeyType key, PType priority)
    : key_(key), priority_(priority), left_(nullptr), right_(nullptr) {}

template<typename KeyType, typename PType, typename ValueType>
class Treap {
 public:
  Treap() = default;
  ~Treap() = default;
  Treap(const vector<pair<KeyType, PType>>& items);
  void Insert(const KeyType &key, const PType &priority);
  int GetHeightOfTreap() const;
  //ValueType Find(const KeyType &key);
  //void Erase();
 private:
  shared_ptr<TreapNode<KeyType, PType, ValueType>> root_;
  void Split(shared_ptr<TreapNode<KeyType, PType, ValueType>> tree, KeyType key, shared_ptr<TreapNode<KeyType, PType, ValueType>> &subtree1, shared_ptr<TreapNode<KeyType, PType, ValueType>> &subtree2);
  void Merge(shared_ptr<TreapNode<KeyType, PType, ValueType>> &tree, shared_ptr<TreapNode<KeyType, PType, ValueType>> tree1, shared_ptr<TreapNode<KeyType, PType, ValueType>> tree2);
  void AddNode(shared_ptr<TreapNode<KeyType, PType, ValueType>> &tree, shared_ptr<TreapNode<KeyType, PType, ValueType>> new_node);
  int GetHeight(shared_ptr<TreapNode<KeyType, PType, ValueType>> node) const;
};

template<typename KeyType, typename PType, typename ValueType>
Treap<KeyType, PType, ValueType>::Treap(const vector<pair<KeyType, PType>> &items) {
  for (const auto& item : items) {
    this->Insert(item.first, item.second);
  }
}

template<typename KeyType, typename PType, typename ValueType>
void Treap<KeyType, PType, ValueType>::Split(shared_ptr<TreapNode<KeyType, PType, ValueType>> tree, KeyType key, shared_ptr<TreapNode<KeyType, PType, ValueType>> &subtree1, shared_ptr<TreapNode<KeyType, PType, ValueType>> &subtree2) {
  if (tree == nullptr) {
    subtree1 = subtree2 = nullptr;
    return;
  }
  if (key > tree->key_) {
    Split(tree->right_, key, tree->right_, subtree2);
    subtree1 = tree;
  } else {
    Split(tree->left_, key, subtree1, tree->left_);
    subtree2 = tree;
  }
}

template<typename KeyType, typename PType, typename ValueType>
void Treap<KeyType, PType, ValueType>::Merge(shared_ptr<TreapNode<KeyType, PType, ValueType>> &tree, shared_ptr<TreapNode<KeyType, PType, ValueType>> tree1, shared_ptr<TreapNode<KeyType, PType, ValueType>> tree2) {
  if (tree1 == nullptr) {
    tree = tree2;
  }
  if (tree2 == nullptr) {
    tree = tree1;
  }
  if (tree1->priority_ > tree2->priority_) {
    Merge(tree1->right_, tree1->right_, tree2);
    tree = tree1;
  } else {
    Merge(tree2->left_, tree1, tree2->left_);
    tree = tree2;
  }
}

template<typename KeyType, typename PType, typename ValueType>
void Treap<KeyType, PType, ValueType>::Insert(const KeyType &key, const PType &priority) {
  AddNode(root_, make_shared<TreapNode<KeyType, PType, ValueType>>(key, priority));
};

template<typename KeyType, typename PType, typename ValueType>
void Treap<KeyType, PType, ValueType>::AddNode(shared_ptr<TreapNode<KeyType, PType, ValueType>> &tree, shared_ptr<TreapNode<KeyType, PType, ValueType>> new_node) {
  if (tree == nullptr) {
    tree = new_node;
  } else if (new_node->priority_ >= tree->priority_) {
    Split(tree, new_node->key_, new_node->left_, new_node->right_);
    tree = new_node;
  } else {
    AddNode((new_node->key_ > tree->key_ ? tree->right_ : tree->left_), new_node);
  }
}

template<typename KeyType, typename PType, typename ValueType>
int Treap<KeyType, PType, ValueType>::GetHeightOfTreap() const {
  return GetHeight(root_);
}

template<typename KeyType, typename PType, typename ValueType>
int Treap<KeyType, PType, ValueType>::GetHeight(shared_ptr<TreapNode<KeyType, PType, ValueType>> node) const {
  if (node == nullptr) {
    return 0;
  }
  return 1 + std::max(GetHeight(node->left_), GetHeight(node->right_));
}

#endif //E1_TREAP_HEIGHT_TREAP_H
