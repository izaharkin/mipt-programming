//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E_MAXFLOW_RELABLETOFRONTSTRATEGY_H
#define E_MAXFLOW_RELABLETOFRONTSTRATEGY_H

#include <list>

#include "Matrix.h"
#include "IMaxFlowFinderStrategy.h"

using std::list;
using std::min;

class RelableToFrontStrategy : public IMaxFlowFinderStrategy {
 public:
  double findMaxFlow(const Graph &graph, int start, int end) noexcept override;
 private:
  int n_;
  Matrix<double> flow_;
  Matrix<double> capacity_;
  vector<int> height_;
  vector<double> excess_flow_;
  Matrix<int> neighbours_;
  vector<vector<int>::iterator> current_;

  void Initialize(const Graph &graph, int start, int end) noexcept;
  void Push(int u, int v) noexcept;
  void Relable(int u) noexcept;
  void Discharge(int u) noexcept;
};

#endif //E_MAXFLOW_RELABLETOFRONTSTRATEGY_H
