//
// Created by ilya on 06.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "StringRestoringSolver.h"

void StringRestoringSolver::Input(istream &in) {
  string input_string;
  if (getline(in, input_string)) {
    int x;
    std::stringstream in_stream(input_string);
    while (in_stream >> x) {
      prefix_func_.push_back(x);
    }
  }
}

void StringRestoringSolver::Run() {
  result_ = StringTransformer::GetStringFromPrefixFunction(prefix_func_);
}

void StringRestoringSolver::Output(ostream &out) {
  out << result_;
}