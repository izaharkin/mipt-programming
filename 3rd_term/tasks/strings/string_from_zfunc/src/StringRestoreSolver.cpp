//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "StringRestoreSolver.h"

void StringRestoreSolver::Input(istream &in) {
  string input_string;
  if (getline(in, input_string)) {
    int x;
    std::stringstream in_stream(input_string);
    while (in_stream >> x) {
      prefix_func_.push_back(x);
    }
  }
}

void StringRestoreSolver::Run() {
  result_ = StringConverter::GetStringFromZFunction(prefix_func_);
}

void StringRestoreSolver::Output(ostream &out) {
  out << result_;
}