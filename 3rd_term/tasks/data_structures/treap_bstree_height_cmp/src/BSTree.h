//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E1_TREAP_HEIGHT_BSTREE_H
#define E1_TREAP_HEIGHT_BSTREE_H

#include <memory>
#include <vector>

using std::make_shared;
using std::pair;
using std::shared_ptr;
using std::vector;

template<typename KeyType, typename ValueType>
class BSTreeNode {
 public:
  KeyType key_;
  ValueType value_;
  shared_ptr<BSTreeNode> left_;
  shared_ptr<BSTreeNode> right_;
  BSTreeNode() = default;
  ~BSTreeNode() = default;
  BSTreeNode(KeyType key, ValueType value);
};

template<typename KeyType, typename ValueType>
BSTreeNode<KeyType, ValueType>::BSTreeNode(KeyType key, ValueType value)
    : key_(key), value_(value), left_(nullptr), right_(nullptr) {}

template<typename KeyType, typename ValueType>
class BSTree {
 public:
  BSTree() = default;
  ~BSTree() = default;
  BSTree(const vector<pair<KeyType, ValueType>>& items);
  void Insert(const KeyType &key, const ValueType &value);
  int GetHeightOfTree() const;
 private:
  shared_ptr<BSTreeNode<KeyType, ValueType>> root_;
  void AddNode(shared_ptr<BSTreeNode<KeyType, ValueType>> &tree, shared_ptr<BSTreeNode<KeyType, ValueType>> new_node);
  int GetHeight(shared_ptr<BSTreeNode<KeyType, ValueType>> node) const;
};

template<typename KeyType, typename ValueType>
BSTree<KeyType, ValueType>::BSTree(const vector<pair<KeyType, ValueType>> &items) {
  for (const auto& item : items) {
    this->Insert(item.first, item.second);
  }
}

template<typename KeyType, typename ValueType>
void BSTree<KeyType, ValueType>::Insert(const KeyType &key, const ValueType &value) {
  this->AddNode(root_, make_shared<BSTreeNode<KeyType, ValueType>>(key, value));
}

template<typename KeyType, typename ValueType>
void BSTree<KeyType, ValueType>::AddNode(shared_ptr<BSTreeNode<KeyType, ValueType>> &tree, shared_ptr<BSTreeNode<KeyType, ValueType>> new_node) {
  if (tree == nullptr) {
    tree = new_node;
  } else if (new_node->key_ > tree->key_) {
    AddNode(tree->right_, new_node);
  } else {
    AddNode(tree->left_, new_node);
  }
}

template <typename KeyType, typename ValueType>
int BSTree<KeyType, ValueType>::GetHeightOfTree() const {
  return GetHeight(root_);
}

template <typename KeyType, typename ValueType>
int BSTree<KeyType, ValueType>::GetHeight(shared_ptr<BSTreeNode<KeyType, ValueType>> node) const {
  if (node == nullptr) {
    return 0;
  }
  return 1 + std::max(GetHeight(node->left_), GetHeight(node->right_));
}

#endif //E1_TREAP_HEIGHT_BSTREE_H
