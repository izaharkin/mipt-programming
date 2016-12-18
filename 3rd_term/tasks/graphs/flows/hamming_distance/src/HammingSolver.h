//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_HAMMING_HAMMINGSOLVER_H
#define F_HAMMING_HAMMINGSOLVER_H

#include <iostream>

#include "Graph.h"
#include "GraphBuilder.h"
#include "MaxFlowFinder.h"

using std::endl;
using std::istream;
using std::ostream;
using std::string;

class HammingSolver {
 public:
  void Input(istream &in);
  void Run();
  void Output(ostream &out) const;
 private:
  string text_;
  string pattern_;
  int min_dist_;
  string result_pat_;
  string result_text_;
};

#endif //F_HAMMING_HAMMINGSOLVER_H
