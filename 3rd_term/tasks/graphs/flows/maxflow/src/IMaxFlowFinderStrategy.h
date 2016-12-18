//
// Created by izakharkin on 12.11.16.
// Copyright (c) 2016, izakharkin. All rights reserved.
//

#ifndef E_MAXFLOW_IMAXFLOWFINDERSTRATEGY_H
#define E_MAXFLOW_IMAXFLOWFINDERSTRATEGY_H

#include "Graph.h"

class IMaxFlowFinderStrategy {
 public:
  virtual double findMaxFlow(const Graph &, int, int) noexcept = 0;
  virtual ~IMaxFlowFinderStrategy() noexcept {}
};

#endif //E_MAXFLOW_IMAXFLOWFINDERSTRATEGY_H
