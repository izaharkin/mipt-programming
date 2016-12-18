//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_HAMMING_MAXFLOWFINDER_H
#define F_HAMMING_MAXFLOWFINDER_H

#include "IStrategy.h"
#include "DinicStrategy.h"

class MaxFlowFinder {
 public:
  MaxFlowFinder();
  MaxFlowFinder(string &&strategy);
  int FindMaxFlow(Graph &graph) const noexcept;
  pair<string, string> GetRestoredStrings(Graph &graph, const string &text, const string &pattern) const noexcept;
 private:
  shared_ptr<IStrategy> strategy_;
};

#endif //F_HAMMING_MAXFLOWFINDER_H
