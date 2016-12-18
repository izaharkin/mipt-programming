//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef B2_FROM_ZFUNCTION_STRINGFUNCTIONS_H
#define B2_FROM_ZFUNCTION_STRINGFUNCTIONS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class StringFunctions {
 public:
  StringFunctions() = delete;
  StringFunctions(const StringFunctions &) = delete;
  StringFunctions(StringFunctions &&) = delete;

  static vector<int> partial_prefix_function(const vector<int> &old_prefix, const string &str, int position);
};

#endif //B2_FROM_ZFUNCTION_STRINGFUNCTIONS_H
