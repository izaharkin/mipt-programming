//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "SuffixArray.h"

SuffixArray::SuffixArray(const string &initial_string) {
  BuildSuffixArrayFromString(initial_string);
}

void SuffixArray::InitializeStartState() {
  positions_.resize(length_, 0);
  dig_sort_.resize(kAlphabetSize_, 0);
  eqv_classes_.resize(length_, vector<int>(length_, 0));
  for (const auto &cur_symbol : str_) {
    dig_sort_[cur_symbol] += 1;
  }
  for (int i = 1; i < kAlphabetSize_; ++i) {
    dig_sort_[i] += dig_sort_[i - 1];
  }
  for (int i = 0; i < length_; ++i) {
    positions_[--dig_sort_[str_[i]]] = i;
  }
  eqv_classes_[0][positions_[0]] = 0;
  num_of_classes_ = 1;
  for (int i = 1; i < length_; ++i) {
    if (str_[positions_[i]] != str_[positions_[i - 1]]) {
      num_of_classes_ += 1;
    }
    eqv_classes_[0][positions_[i]] = num_of_classes_ - 1;
  }
}

SuffixArray SuffixArray::BuildSuffixArrayFromString(const string &str) {
  str_ = str;
  length_ = str_.length();
  InitializeStartState();
  vector<int> new_positions(length_, 0);
  vector<int> new_eqv_classes(length_, 0);
  int phase_num = 1;
  for (int offset = 0; (1 << offset) < length_; ++offset) {
    for (int i = 0; i < length_; ++i) {
      new_positions[i] = positions_[i] - (1 << offset);
      if (new_positions[i] < 0) {
        new_positions[i] += length_;
      }
    }
    dig_sort_.assign(num_of_classes_, 0);
    for (int i = 0; i < length_; ++i) {
      dig_sort_[eqv_classes_[phase_num - 1][new_positions[i]]] += 1;
    }
    for (int i = 1; i < num_of_classes_; ++i) {
      dig_sort_[i] += dig_sort_[i - 1];
    }
    for (int i = length_ - 1; i >= 0; --i) {
      positions_[--dig_sort_[eqv_classes_[phase_num - 1][new_positions[i]]]] = new_positions[i];
    }
    new_eqv_classes[positions_[0]] = 0;
    num_of_classes_ = 1;
    for (int i = 1; i < length_; ++i) {
      int pivot1 = (positions_[i] + (1 << offset)) % length_;
      int pivot2 = (positions_[i - 1] + (1 << offset)) % length_;
      if (eqv_classes_[phase_num- 1][positions_[i]] != eqv_classes_[phase_num - 1][positions_[i - 1]] ||
          eqv_classes_[phase_num - 1][pivot1] != eqv_classes_[phase_num - 1][pivot2]) {
        num_of_classes_ += 1;
      }
      new_eqv_classes[positions_[i]] = num_of_classes_ - 1;
    }
    for (int i = 0; i < length_; ++i) {
      eqv_classes_[phase_num][i] = new_eqv_classes[i];
    }
    phase_num += 1;
  }
  return *this;
}

int SuffixArray::GetLongestCommonPrefix(int index1, int index2) const {
  int lcp = 0;
  size_t log_floored = GetLog2(length_);
  for (int phase_num = log_floored; phase_num >= 0; --phase_num) {
    if (eqv_classes_[phase_num][index1] == eqv_classes_[phase_num][index2]) {
      lcp += (1 << phase_num);
      index1 += (1 << phase_num);
      index2 += (1 << phase_num);
    }
  }
  return lcp;
}

int SuffixArray::GetPositionAt(int index) const {
  return positions_[index];
}