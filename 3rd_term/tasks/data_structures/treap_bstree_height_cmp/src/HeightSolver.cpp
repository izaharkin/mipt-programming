//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "HeightSolver.h"

void HeightSolver::Input(istream &in) {
  int number_of_items;
  in >> number_of_items;
  for (int i = 0; i < number_of_items; ++i) {
    int x, y;
    in >> x >> y;
    items_.push_back(make_pair(x, y));
  }
}

void HeightSolver::Run() {
  Treap<int, int, int> treap(items_);
  BSTree<int, int> bstree(items_);
  answer_ = bstree.GetHeightOfTree() - treap.GetHeightOfTreap();
}

void HeightSolver::Output(ostream &out) {
  out << answer_;
}