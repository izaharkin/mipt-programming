//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef D_DIFFERENT_SUBSRTINGS_SUBSTRINGQUANTITYSOLVER_H
#define D_DIFFERENT_SUBSRTINGS_SUBSTRINGQUANTITYSOLVER_H

#include <iostream>

#include "DistinctStringSolver.h"

class SubstringsQuantitySolver {
 public:
  void Input(std::istream &in);
  void Run();
  void Output(std::ostream &out);
 private:
  std::string str_;
  int answer_;
};

#endif //D_DIFFERENT_SUBSRTINGS_SUBSTRINGQUANTITYSOLVER_H
