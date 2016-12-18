//
// Created by izakharkin on 12.11.16.
// Copyright (c) 2016, izakharkin. All rights reserved.
//

#ifndef E_MAXFLOW_MAXFLOWFINDER_H
#define E_MAXFLOW_MAXFLOWFINDER_H

#include "Graph.h"
#include "IMaxFlowFinderStrategy.h"

class MaxFlowFinder {
 public:
  void SetGraph(const Graph &graph) noexcept;
  void FindMaxFlow(IMaxFlowFinderStrategy *strategy, int start_vertex, int end_vertex) noexcept;
  double GetMaxFlowValue() const noexcept;
 private:
  Graph graph_;
  double max_flow_;
};

#endif //E_MAXFLOW_MAXFLOWFINDER_H
