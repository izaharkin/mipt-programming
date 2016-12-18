//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef A_SUBSTRING_IFINDSUBSTRINGSTRATEGY_H
#define A_SUBSTRING_IFINDSUBSTRINGSTRATEGY_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class IFindSubstringStrategy {
 public:
  virtual vector<int> GetSubstringEntrances(const string &text, const string &pattern) noexcept = 0;
};

#endif //A_SUBSTRING_IFINDSUBSTRINGSTRATEGY_H
