//
// Created by ilya on 06.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "StringTransformer.h"

using  namespace StringTransformer;

string StringTransformer::GetStringFromPrefixFunction(const vector<int> &prefix_values) {
  string str = "a";
  vector<int> cur_prefix({0});
  for (int i = 1; i < prefix_values.size(); ++i) {
    for (int j = 0; j < kAlphabet.size(); ++j) {
      str += kAlphabet[j];
      vector<int> prefix = StringFunctions::partial_prefix_function(cur_prefix, str, i);
      if (prefix[i] == prefix_values[i]) {
        break;
      }
      str.pop_back();
    }
    cur_prefix.push_back(prefix_values[i]);
  }
  return str;
}