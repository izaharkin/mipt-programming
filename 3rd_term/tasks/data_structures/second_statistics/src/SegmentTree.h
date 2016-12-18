//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_SECOND_STATICSTICS_SEGMENTTREE_H
#define F_SECOND_STATICSTICS_SEGMENTTREE_H

#include <memory>
#include <vector>

#include "constants.h"

using std::make_pair;
using std::make_unique;
using std::max;
using std::min;
using std::pair;
using std::unique_ptr;
using std::vector;

class SegmentTree {
 public:
  static unique_ptr <SegmentTree> BuildSegmentTreeFromVector(const vector<int> &elements/*,const function<int(int, int)> &operation*/);
  int GetSecondMinimum(int left_bound, int right_bound);
 private:
  vector<pair < int, int>> tree_;
//  function<int(int, int)> associative_operation;
  static pair<int, int> GetMinAndSecondMin(const pair<int, int> &item1, const pair<int, int> &item2);
};

#endif //F_SECOND_STATICSTICS_SEGMENTTREE_H
