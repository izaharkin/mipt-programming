//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "StringConverter.h"

string StringConverter::GetStringFromPrefixFunction(const vector<int> &prefix_values) {
  string str = "a";
  vector<int> cur_prefix({0});
  for (int i = 1; i < prefix_values.size(); ++i) {
    for (int j = 0; j < kAlphabet.size(); ++j) {
      string temp_string = str + kAlphabet[j];
      vector<int> prefix = StringFunctions::partial_prefix_function(cur_prefix, temp_string, i);
      if (prefix[i] == prefix_values[i]) {
        str = temp_string;
        break;
      }
    }
    cur_prefix.push_back(prefix_values[i]);
  }
  return str;
}

vector<int> StringConverter::GetPrefixFunctionFromZFunction(const vector<int> &z_values) {
  vector<int> prefix_values(z_values.size(), 0);
  for (int i = 1; i < z_values.size(); ++i) {
    for (int j = z_values[i] - 1; j >= 0; --j) {
      if (prefix_values[i + j] > 0) {
        break;
      } else {
        prefix_values[i + j] = j + 1;
      }
    }
  }
  return prefix_values;
}

string StringConverter::GetStringFromZFunction(const vector<int> &z_values) {
  vector<int> prefix_values = GetPrefixFunctionFromZFunction(z_values);
  string str = GetStringFromPrefixFunction(prefix_values);
  return str;
}