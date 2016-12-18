//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "AdjList.h"

AdjList::AdjList() noexcept
    : adj_list_(0) {}

AdjList::~AdjList() noexcept {}

AdjList::AdjList(int size)noexcept
    : adj_list_(size) {}

AdjList::AdjList(const Matrix<int> &matrix) noexcept {
  adj_list_ = matrix;
}

int AdjList::GetSize() const noexcept {
  return adj_list_.size();
}

const vector<int> &AdjList::operator[](int vertex) const noexcept {
  return adj_list_[vertex];
}

vector<int> &AdjList::operator[](int vertex) noexcept {
  return adj_list_[vertex];
}