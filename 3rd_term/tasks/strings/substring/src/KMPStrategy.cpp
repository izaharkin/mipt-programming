//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "KMPStrategy.h"

vector<int> KMPStrategy::GetSubstringEntrances(const string &text, const string &pattern) noexcept {
  int text_len = static_cast<int>(text.length());
  int pat_len = static_cast<int>(pattern.length());
  vector<int> entrances;
  vector<int> prefix_values = StringFunctions::prefix_function(pattern + '#' + text);
  for (int i = 0; i < text_len; ++i) {
    if (prefix_values[pat_len + 1 + i] == pat_len) {
      entrances.push_back(i - (pat_len - 1));
    }
  }
  return entrances;
}