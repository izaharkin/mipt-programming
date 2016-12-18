//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef A_SUBSTRING_SUBSTRINGFINDER_H
#define A_SUBSTRING_SUBSTRINGFINDER_H

#include <memory>
#include <string>
#include <vector>

#include "IFindSubstringStrategy.h"
#include "KMPStrategy.h"

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

class SubstringFinder {
 public:
  SubstringFinder();
  ~SubstringFinder() = default;
  SubstringFinder(string &&strategy_name);
  vector<int> GetAllEntrances(const string &text, const string &pattern); // do as r-value: &&
 private:
  shared_ptr<IFindSubstringStrategy> strategy_;
};

#endif //A_SUBSTRING_SUBSTRINGFINDER_H
