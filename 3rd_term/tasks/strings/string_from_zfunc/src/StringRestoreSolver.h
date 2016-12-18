//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef B2_FROM_ZFUNCTION_STRINGRESTORESOLVER_H
#define B2_FROM_ZFUNCTION_STRINGRESTORESOLVER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "StringConverter.h"

using std::istream;
using std::ostream;

class StringRestoreSolver {
 public:
  void Input(istream &in);
  void Run();
  void Output(ostream &out);
 private:
  vector<int> prefix_func_;
  string result_;
};

#endif //B2_FROM_ZFUNCTION_STRINGRESTORESOLVER_H
