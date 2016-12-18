//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "SegmentTree.h"

unique_ptr<SegmentTree> SegmentTree::BuildSegmentTreeFromVector(const vector<int> &elements/*,
                                                                const function<int(int, int)> &operation*/) {
  SegmentTree segment_tree;
  int n = elements.size();
  segment_tree.tree_.resize(2 * n, make_pair(INF, INF));
//  segment_tree.associative_operation = operation;
  for (int i = 0; i < n; ++i) {
    segment_tree.tree_[n - 1 + i].first = elements[i];
    segment_tree.tree_[n - 1 + i].second = INF;
  }
  for (int i = n - 2; i >= 0; --i) {
    segment_tree.tree_[i] = GetMinAndSecondMin(segment_tree.tree_[2 * i + 1], segment_tree.tree_[2 * i + 2]);
  }
  return make_unique<SegmentTree>(segment_tree);
}

int SegmentTree::GetSecondMinimum(int left, int right) {
  pair<int, int> left_result = make_pair(INF, INF);
  pair<int, int> right_result = make_pair(INF, INF);
  left += tree_.size() / 2 - 1;
  right += tree_.size() / 2 - 1;
  while (left < right) {
    if (left % 2 == 0) {
      left_result = GetMinAndSecondMin(left_result, tree_[left]);
    }
    left = left >> 1;
    if (right % 2 == 1) {
      right_result = GetMinAndSecondMin(tree_[right], right_result);
    }
    right = (right - 2) >> 1;
  }
  if (left == right) {
    left_result = GetMinAndSecondMin(left_result, tree_[left]);
  }
  return GetMinAndSecondMin(left_result, right_result).second;
}

pair<int, int> SegmentTree::GetMinAndSecondMin(const pair<int, int> &item1, const pair<int, int> &item2) {
  int minimum = min(item1.first, item2.first);
  int second_minimum = min(max(item1.first, item2.first), min(item1.second, item2.second));
  return make_pair(minimum, second_minimum);
}