//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef E_MAXFLOW_GRAPH_H
#define E_MAXFLOW_GRAPH_H

#include "EdgeList.h"

class Graph {
 public:
  Graph() noexcept;
  ~Graph() noexcept;
  Graph(const EdgeList &edge_list) noexcept;
  Graph &operator=(const EdgeList &edge_list) noexcept;
  void SetNumOfVertices(int num_of_vertices) noexcept;
  int GetNumOfVertices() const noexcept;
  EdgeList GetEdgeList() const noexcept;
 private:
  int num_of_vertices_;
  EdgeList edge_list_;
};

#endif //E_MAXFLOW_GRAPH_H
