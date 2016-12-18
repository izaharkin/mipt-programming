//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef A_SUBSTRING_STRINGFUNCTIONS_H
#define A_SUBSTRING_STRINGFUNCTIONS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class StringFunctions {
 public:
  static vector<int> prefix_function(const string &str) noexcept;
};

#endif //A_SUBSTRING_STRINGFUNCTIONS_H
