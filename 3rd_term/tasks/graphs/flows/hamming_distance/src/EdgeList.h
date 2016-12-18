//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_HAMMING_EDGELIST_H
#define F_HAMMING_EDGELIST_H

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;
using std::vector;

class Edge {
 public:
  short from_;
  short to_;
  char capacity_;
  char flow_;
  Edge() noexcept;
  Edge(const Edge &edge) noexcept;
  Edge(short, short, char, char) noexcept;
};

class EdgeList {
 public:
  EdgeList() noexcept;
  ~EdgeList() noexcept;
  void AddEdge(const Edge &edge) noexcept;
  int GetSize() const noexcept;
  shared_ptr<Edge> operator[](int index) noexcept;
 private:
  vector<shared_ptr<Edge>> edge_list_;
};

#endif //F_HAMMING_EDGELIST_H
