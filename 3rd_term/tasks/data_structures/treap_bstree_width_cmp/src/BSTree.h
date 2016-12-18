//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E1_TREAP_HEIGHT_BSTREE_H
#define E1_TREAP_HEIGHT_BSTREE_H

#include <memory>
#include <queue>
#include <vector>

using std::make_shared;
using std::pair;
using std::queue;
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
  int GetWidthOfTree() const;
 private:
  shared_ptr<BSTreeNode<KeyType, ValueType>> root_;
  void AddNode(shared_ptr<BSTreeNode<KeyType, ValueType>> &tree, shared_ptr<BSTreeNode<KeyType, ValueType>> new_node);
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

template<typename KeyType, typename ValueType>
class BfsItem {
 public:
  shared_ptr<BSTreeNode<KeyType, ValueType>> node_;
  int wave_number_;
  BfsItem(shared_ptr<BSTreeNode<KeyType, ValueType>>, int wave);
};

template<typename KeyType, typename ValueType>
BfsItem<KeyType, ValueType>::BfsItem(shared_ptr<BSTreeNode<KeyType, ValueType>> node, int wave)
    : node_(node), wave_number_(wave) {}

template<typename KeyType, typename ValueType>
int BSTree<KeyType, ValueType>::GetWidthOfTree() const {
  if (root_ == nullptr) {
    return 0;
  }
  queue<BfsItem<KeyType, ValueType>> bfs_queue;
  int max_width = -1;
  int width = 1;
  int prev_wave_num = -1;
  bfs_queue.push(BfsItem<KeyType, ValueType>(root_, 0));
  while (!bfs_queue.empty()) {
    BfsItem<KeyType, ValueType> current = bfs_queue.front();
    bfs_queue.pop();
    if (current.wave_number_ == prev_wave_num) {
      width += 1;
    } else {
      if (width > max_width) {
        max_width = width;
      }
      width = 1;
    }
    prev_wave_num = current.wave_number_;
    if (current.node_->left_ != nullptr) {
      bfs_queue.push(BfsItem<KeyType, ValueType>(current.node_->left_, current.wave_number_ + 1));
    }
    if (current.node_->right_ != nullptr) {
      bfs_queue.push(BfsItem<KeyType, ValueType>(current.node_->right_, current.wave_number_ + 1));
    }
  }
  return max_width;
}

#endif //E1_TREAP_HEIGHT_BSTREE_H
