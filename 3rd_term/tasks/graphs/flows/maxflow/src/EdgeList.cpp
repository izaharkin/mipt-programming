//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "EdgeList.h"

Edge::Edge() noexcept
    : from_(-1), to_(-1), weight_(kInf) {}

Edge::Edge(int from, int to, unsigned long long weight) noexcept
    : from_(from), to_(to), weight_(weight) {}

bool Edge::operator<(const Edge &second_edge) const noexcept {
  return this->weight_ < second_edge.weight_;
}

EdgeList::EdgeList() noexcept
    : edge_list_(0) {}

EdgeList::EdgeList(const vector<Edge> &edges) noexcept {
  edge_list_ = edges;
}

int EdgeList::GetSize() const noexcept {
  return edge_list_.size();
}

Edge EdgeList::operator[](int index) const noexcept {
  return edge_list_[index];
}
