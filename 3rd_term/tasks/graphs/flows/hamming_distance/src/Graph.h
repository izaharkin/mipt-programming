//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_HAMMING_GRAPH_H
#define F_HAMMING_GRAPH_H

#include <memory>
#include <vector>

#include "AdjList.h"
#include "EdgeList.h"

using std::shared_ptr;
using std::vector;

class Graph {
 public:
  Graph() noexcept;
  ~Graph() noexcept;
  Graph(int num_of_vertices) noexcept;
  Graph(const AdjList &adj_list) noexcept;
  Graph(const Matrix<int> &adj_list, const EdgeList &edge_list) noexcept;
  void AddEdge(const Edge &edge) noexcept;
  int GetNumOfVertices() const noexcept;
  int GetNumOfEdges() const noexcept;
  void IncreasePersistentFlow() noexcept;
  int GetPersistentFlow() const noexcept;
  vector<int> &operator[](int vertex) noexcept;
  shared_ptr<Edge> operator()(int edge) noexcept;
  const vector<int> &operator[](int vertex) const noexcept;
 private:
  AdjList adj_list_;
  EdgeList edge_list_;
  int persistent_flow_;
};

#endif //F_HAMMING_GRAPH_H
