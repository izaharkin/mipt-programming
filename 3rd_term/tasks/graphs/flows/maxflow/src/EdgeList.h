//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E_MAXFLOW_EDGELIST_H
#define E_MAXFLOW_EDGELIST_H

#include <vector>

#include "constants.h"

using std::vector;

class Edge {
 public:
  int from_;
  int to_;
  unsigned long long weight_;
  Edge() noexcept;
  Edge(int, int, unsigned long long) noexcept;
  bool operator<(const Edge &second_edge) const noexcept;
};

class EdgeList {
 public:
  EdgeList() noexcept;
  ~EdgeList() noexcept = default;
  explicit EdgeList(const vector<Edge> &edges) noexcept;
  int GetSize() const noexcept;
  Edge operator[](int index) const noexcept;
 private:
  vector<Edge> edge_list_;
};

#endif //E_MAXFLOW_EDGELIST_H
