//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "SubstringsQuantitySolver.h"

void SubstringsQuantitySolver::Input(std::istream &in) {
  in >> str_;
}

void SubstringsQuantitySolver::Run() {
  DifferentStringsSolver solver;
  answer_ = solver.GetQuantityOfDifferentSubstrings(str_);
}

void SubstringsQuantitySolver::Output(std::ostream &out) {
  out << answer_;
}