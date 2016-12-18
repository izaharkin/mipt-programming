//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef A_SUBSTRING_KMPSTRATEGY_H
#define A_SUBSTRING_KMPSTRATEGY_H

#include "IFindSubstringStrategy.h"
#include "StringFunctions.h"

class KMPStrategy : public IFindSubstringStrategy {
 public:
  virtual vector<int> GetSubstringEntrances(const string &text, const string &pattern) noexcept override;
};

#endif //A_SUBSTRING_KMPSTRATEGY_H
