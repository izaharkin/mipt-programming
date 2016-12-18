//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef A_SUBSTRING_SUBSTRINGSOLVER_H
#define A_SUBSTRING_SUBSTRINGSOLVER_H

#include <iostream>
#include <string>
#include <vector>

#include "SubstringFinder.h"

using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::endl;

class SubstringSolver {
 public:
  void Input(istream &in);
  void Run();
  void Output(ostream &out);
 private:
  string text_;
  string pattern_;
  vector<int> positions_;
};

#endif //A_SUBSTRING_SUBSTRINGSOLVER_H
