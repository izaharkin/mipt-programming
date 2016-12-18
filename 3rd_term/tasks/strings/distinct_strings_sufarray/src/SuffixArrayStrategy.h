//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef D_DIFFERENT_SUBSRTINGS_SUFFIXARRAYSTRATEGY_H
#define D_DIFFERENT_SUBSRTINGS_SUFFIXARRAYSTRATEGY_H

#include "constants.h"
#include "SuffixArray.h"
#include "IStrategy.h"

class SuffixArrayStrategy : IStrategy {
 public:
  virtual int GetAmountOfDifferentSubstrings(const std::string &str) override;
};

#endif //D_DIFFERENT_SUBSRTINGS_SUFFIXARRAYSTRATEGY_H
