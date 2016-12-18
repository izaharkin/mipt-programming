//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "Graph.h"

Graph::Graph() noexcept
    : adj_list_(), edge_list_(), persistent_flow_(0) {}

Graph::Graph(int num_of_vertices) noexcept
    : adj_list_(num_of_vertices), edge_list_(), persistent_flow_(0) {}

Graph::Graph(const AdjList &adj_list) noexcept
    : adj_list_(adj_list), edge_list_(), persistent_flow_(0) {}

Graph::Graph(const Matrix<int> &adj_list, const EdgeList &edge_list) noexcept
    : adj_list_(adj_list), edge_list_(edge_list), persistent_flow_(0) {}

Graph::~Graph() noexcept {}

void Graph::AddEdge(const Edge &edge) noexcept {
  edge_list_.AddEdge(edge);
}

int Graph::GetNumOfVertices() const noexcept {
  return adj_list_.GetSize();
}

int Graph::GetNumOfEdges() const noexcept {
  return edge_list_.GetSize();
}

void Graph::IncreasePersistentFlow() noexcept {
  persistent_flow_ += 1;
}

int Graph::GetPersistentFlow() const noexcept {
  return persistent_flow_;
}

vector<int>& Graph::operator[](int vertex) noexcept {
  return adj_list_[vertex];
}

shared_ptr<Edge> Graph::operator()(int edge) noexcept {
  return edge_list_[edge];
}

const vector<int> &Graph::operator[](int vertex) const noexcept {
  return adj_list_[vertex];
}