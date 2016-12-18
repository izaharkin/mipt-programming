//
// Created by ilya on 06.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef B1_FROM_PREFIX_STRINGFUNCTIONS_H
#define B1_FROM_PREFIX_STRINGFUNCTIONS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace StringFunctions {
  vector<int> partial_prefix_function(const vector<int> &old_prefix, const string &str, int position);
};

#endif //B1_FROM_PREFIX_STRINGFUNCTIONS_H
