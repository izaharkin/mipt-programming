//
// Created by izakharkin on 10.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef TRADEARBITRAGE_GRAPH_H
#define TRADEARBITRAGE_GRAPH_H

#include <memory>
#include <vector>

#include "Edge.h"

using std::unique_ptr;
using std::vector;

class Graph {
 public:
  Graph();
  int GetNodeCount() const;
  const vector<Edge> &GetEdgeList() const;
  void SetNodeCount(int count);
  void SetEdges(vector<Edge> edges);
 private:
  vector<Edge> edges_;
  int node_count_;
};


#endif //TRADEARBITRAGE_GRAPH_H
