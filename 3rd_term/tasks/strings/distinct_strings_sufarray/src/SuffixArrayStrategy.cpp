//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "SuffixArrayStrategy.h"

int SuffixArrayStrategy::GetAmountOfDifferentSubstrings(const string &str) {
  string ended_string = str + kDistinctSymbol;
  SuffixArray suf_array(ended_string);
  int quantity = (ended_string.length() * (ended_string.length() - 1)) >> 1;
  for (int i = 0; i < ended_string.length() - 1; ++i) {
    quantity -= suf_array.GetLongestCommonPrefix(suf_array.GetPositionAt(i),
                                                 suf_array.GetPositionAt(i + 1));
  }
  return quantity;
}