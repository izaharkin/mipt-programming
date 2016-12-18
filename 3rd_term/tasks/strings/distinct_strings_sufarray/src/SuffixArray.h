//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef D_DIFFERENT_SUBSRTINGS_SUFFIXARRAY_H
#define D_DIFFERENT_SUBSRTINGS_SUFFIXARRAY_H

#include <string>
#include <vector>

#include "utils.h"

using std::string;
using std::vector;

class SuffixArray {
 public:
  SuffixArray() = delete;
  ~SuffixArray() = default;
  SuffixArray(const string &initial_string);
  int GetLongestCommonPrefix(int index1, int index2) const;
  int GetPositionAt(int index) const;
 private:
  const int kAlphabetSize_ = 256;
  vector<int> dig_sort_;
  vector<std::vector<int>> eqv_classes_;
  std::size_t length_;
  vector<int> positions_;
  string str_;
  int num_of_classes_;

  void InitializeStartState();
  SuffixArray BuildSuffixArrayFromString(const string &str);
};

#endif //D_DIFFERENT_SUBSRTINGS_SUFFIXARRAY_H
