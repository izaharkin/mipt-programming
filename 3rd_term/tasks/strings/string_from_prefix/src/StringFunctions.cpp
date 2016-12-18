//
// Created by ilya on 06.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "StringFunctions.h"

using namespace StringFunctions;

vector<int> StringFunctions::partial_prefix_function(const vector<int> &old_prefix, const string &str, int position) {
  vector<int> prefix = old_prefix;
  prefix.resize(prefix.size() + 1);
  for (int i = position; i < str.length(); ++i) {
    int k = prefix[i-1];
    while (k > 0 && str[i] != str[k]) {
      k = prefix[k-1];
    }
    if (str[i] == str[k]) {
      k += 1;
    }
    prefix[i] = k;
  }
  return prefix;
}