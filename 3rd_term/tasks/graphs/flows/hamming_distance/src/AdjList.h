//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_HAMMING_ADJLIST_H
#define F_HAMMING_ADJLIST_H

#include <vector>

#include "Matrix.h"

using std::vector;

class AdjList {
 public:
  AdjList() noexcept;
  ~AdjList() noexcept;
  AdjList(int size) noexcept;
  AdjList(const Matrix<int> &matrix) noexcept;
  int GetSize() const noexcept;
  const vector<int> &operator[](int vertex) const noexcept;
  vector<int> &operator[](int vertex) noexcept;
 private:
  Matrix<int> adj_list_;
};

#endif //F_HAMMING_ADJLIST_H
