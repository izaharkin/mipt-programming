//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "DistinctStringSolver.h"

DifferentStringsSolver::DifferentStringsSolver()
    : strategy_(std::make_shared<SuffixArrayStrategy>()) {}

int DifferentStringsSolver::GetQuantityOfDifferentSubstrings(const std::string &str) const {
  return strategy_->GetAmountOfDifferentSubstrings(str);
}