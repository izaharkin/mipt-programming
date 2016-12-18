//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E_MAXFLOW_PUSHRELABLESTRATEGY_H
#define E_MAXFLOW_PUSHRELABLESTRATEGY_H

#include "Graph.h"
#include "Matrix.h"
#include "IMaxFlowFinderStrategy.h"

using std::min;

class PushRelableStrategy : public IMaxFlowFinderStrategy {
 public:
  double findMaxFlow(const Graph &graph, int start, int end) noexcept override;
 private:
  int n_;
  Matrix<double> flow_;
  Matrix<double> capacity_;
  vector<int> height_;
  vector<double> excess_flow_;

  void Initialize(const Graph &graph, int start, int end) noexcept;
  void Push(int u, int v) noexcept;
  void Relable(int u) noexcept;
};

#endif //E_MAXFLOW_PUSHRELABLESTRATEGY_H
