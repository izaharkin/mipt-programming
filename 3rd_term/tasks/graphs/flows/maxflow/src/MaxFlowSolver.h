//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E_MAXFLOW_MAXFLOWSOLVER_H
#define E_MAXFLOW_MAXFLOWSOLVER_H

#include <iostream>

#include "Graph.h"
#include "MaxFlowFinder.h"
#include "PushRelableStrategy.h"
#include "RelableToFrontStrategy.h"

using std::istream;
using std::ostream;
using std::endl;

class MaxFlowSolver {
 public:
  void InputRunOutput(istream &in, ostream &out);
 private:
  Graph graph_;
};

#endif //E_MAXFLOW_MAXFLOWSOLVER_H
