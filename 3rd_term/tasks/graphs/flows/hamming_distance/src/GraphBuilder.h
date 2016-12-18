//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_HAMMING_GRAPHBUILDER_H
#define F_HAMMING_GRAPHBUILDER_H

#include <algorithm>

#include "Graph.h"

using std::string;

class GraphBuilder {
 public:
  static Graph BuildGraphFromStrings(const string &text, const string &pattern) noexcept;
};

void InsertEdge(Graph &graph, const Edge &edge);

#endif //F_HAMMING_GRAPHBUILDER_H
