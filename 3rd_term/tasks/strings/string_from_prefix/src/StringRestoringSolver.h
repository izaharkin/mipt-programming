//
// Created by ilya on 06.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef B1_FROM_PREFIX_STRINGRESTORINGSOLVER_H
#define B1_FROM_PREFIX_STRINGRESTORINGSOLVER_H

#include <iostream>
#include <sstream>
#include <vector>

#include "StringTransformer.h"

using std::istream;
using std::ostream;
using std::string;
using std::vector;
using namespace StringTransformer;

class StringRestoringSolver {
 public:
  void Input(istream &in);
  void Run();
  void Output(ostream &out);
 private:
  vector<int> prefix_func_;
  string result_;
};

#endif //B1_FROM_PREFIX_STRINGRESTORINGSOLVER_H
