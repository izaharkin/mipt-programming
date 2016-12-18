//
// Created by izakharkin on 12.11.16.
// Copyright (c) 2016, izakharkin. All rights reserved.
//

#include "MaxFlowFinder.h"

void MaxFlowFinder::SetGraph(const Graph &graph) noexcept {
  graph_ = graph;
}

void MaxFlowFinder::FindMaxFlow(IMaxFlowFinderStrategy *strategy, int start, int end) noexcept {
  IMaxFlowFinderStrategy *max_flow_finder = strategy;
  max_flow_ = max_flow_finder->findMaxFlow(graph_, start, end);
}

double MaxFlowFinder::GetMaxFlowValue() const noexcept {
  return max_flow_;
}
