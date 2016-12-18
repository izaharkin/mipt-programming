//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "SecondStatisticsSolver.h"

void SecondStatisticsSolver::InputRunOutput(istream &in, ostream &out) {
  int n, m;
  in >> n >> m;
  vector<int> elems(n);
  for (int i = 0; i < n; ++i) {
    in >> elems[i];
  }
  unique_ptr<SegmentTree> segment_tree = std::move(SegmentTree::BuildSegmentTreeFromVector(elems/*, std::min<int>*/));
  for (int i = 0; i < m; ++i) {
    int left_bound, right_bound;
    in >> left_bound >> right_bound;
    out << segment_tree->GetSecondMinimum(left_bound - 1, right_bound - 1) << endl;
  }
}