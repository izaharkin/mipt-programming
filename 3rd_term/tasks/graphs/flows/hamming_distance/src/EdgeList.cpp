//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "EdgeList.h"

Edge::Edge() noexcept
    : from_(-1), to_(-1), capacity_(0), flow_(0) {}

Edge::Edge(const Edge &edge) noexcept
    : from_(edge.from_), to_(edge.to_), capacity_(edge.capacity_), flow_(edge.flow_) {}

Edge::Edge(short from, short to, char capacity, char flow) noexcept
    : from_(from), to_(to), capacity_(capacity), flow_(flow) {}

EdgeList::EdgeList() noexcept
    : edge_list_(0) {}

EdgeList::~EdgeList() noexcept {}

void EdgeList::AddEdge(const Edge &edge) noexcept {
  edge_list_.push_back(make_shared<Edge>(edge));
}

int EdgeList::GetSize() const noexcept {
  return edge_list_.size();
}

shared_ptr<Edge> EdgeList::operator[](int index) noexcept {
  return edge_list_[index];
}