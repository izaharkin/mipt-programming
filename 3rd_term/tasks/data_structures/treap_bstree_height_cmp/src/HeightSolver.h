//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E1_TREAP_HEIGHT_HEIGHTSOLVER_H
#define E1_TREAP_HEIGHT_HEIGHTSOLVER_H

#include <iostream>
#include <vector>

#include "BSTree.h"
#include "Treap.h"

using std::istream;
using std::make_pair;
using std::ostream;
using std::pair;
using std::vector;

class HeightSolver {
 public:
  void Input(istream &in);
  void Run();
  void Output(ostream &out);
 private:
  vector<pair<int ,int>> items_;
  int answer_;
};

#endif //E1_TREAP_HEIGHT_HEIGHTSOLVER_H
