//
// Created by ilya on 10.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//
#include "Graph.h"

Graph::Graph()
    : edges_(), node_count_(0) {}

int Graph::GetNodeCount() const {
  return node_count_;
}

const vector<Edge> &Graph::GetEdgeList() const {
  return edges_;
}

void Graph::SetNodeCount(int count) {
  node_count_ = count;
}

void Graph::SetEdges(vector<Edge> edges) {
  edges_ = edges;
}
