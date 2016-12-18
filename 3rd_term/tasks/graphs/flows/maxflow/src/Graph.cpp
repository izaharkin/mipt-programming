//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "Graph.h"

Graph::Graph() noexcept
    : edge_list_() {}

Graph::~Graph() noexcept {}

Graph::Graph(const EdgeList &edge_list) noexcept {
  edge_list_ = EdgeList(edge_list);
}

Graph &Graph::operator=(const EdgeList &edge_list) noexcept {
  edge_list_ = edge_list;
}

void Graph::SetNumOfVertices(int num_of_vertices) noexcept {
  num_of_vertices_ = num_of_vertices;
}

int Graph::GetNumOfVertices() const noexcept {
  return num_of_vertices_;
}

EdgeList Graph::GetEdgeList() const noexcept {
  return edge_list_;
}
