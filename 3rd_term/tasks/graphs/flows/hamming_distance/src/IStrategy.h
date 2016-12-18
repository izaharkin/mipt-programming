//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_HAMMING_ISTRATEGY_H
#define F_HAMMING_ISTRATEGY_H

#include <string>

#include "Graph.h"

using std::pair;
using std::string;

class IStrategy {
 public:
  virtual int FindMaxFlow(Graph &graph) noexcept = 0;
  virtual pair<string, string> GetRestoredStrings(Graph &graph, const string &text, const string &pattern) noexcept = 0;
  virtual ~IStrategy() noexcept {}
};

#endif //F_HAMMING_ISTRATEGY_H
