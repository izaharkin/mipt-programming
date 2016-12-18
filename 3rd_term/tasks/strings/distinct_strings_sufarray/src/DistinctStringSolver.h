//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef D_DIFFERENT_SUBSRTINGS_DISTINCTSTRINGSOLVER_H
#define D_DIFFERENT_SUBSRTINGS_DISTINCTSTRINGSOLVER_H

#include <memory>

#include "SuffixArrayStrategy.h"

class DifferentStringsSolver {
 public:
  DifferentStringsSolver();
  int GetQuantityOfDifferentSubstrings(const std::string &str) const;
 private:
  std::shared_ptr<SuffixArrayStrategy> strategy_;
};

#endif //D_DIFFERENT_SUBSRTINGS_DISTINCTSTRINGSOLVER_H
