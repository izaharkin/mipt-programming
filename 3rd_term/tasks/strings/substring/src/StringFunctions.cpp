//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "StringFunctions.h"

vector<int> StringFunctions::prefix_function(const string &str) noexcept {
  vector<int> prefix(str.length());
  prefix[0] = 0;
  for (int i = 1; i < str.length(); ++i) {
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