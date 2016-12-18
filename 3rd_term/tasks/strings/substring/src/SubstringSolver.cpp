//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "SubstringSolver.h"

void SubstringSolver::Input(istream &in) {
  in >> pattern_;
  in >> text_;
}

void SubstringSolver::Run() {
  SubstringFinder finder("KMP");
  positions_ = finder.GetAllEntrances(text_, pattern_);
}

void SubstringSolver::Output(ostream &out) {
  for (const auto &index : positions_) {
    out << index << " ";
  }
  out << endl;
}