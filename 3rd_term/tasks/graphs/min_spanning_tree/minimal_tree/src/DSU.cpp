/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "DSU.h"

DSU::DSU()
    : parent_(0), rank(0) {}

DSU::~DSU()  {}

DSU::DSU(int size)
    : parent_(size), rank(size, 0) {
  for (int i = 0; i < size; ++i) {
    parent_[i] = i; // All elements are disjoint
  }
}

int DSU::Get(int elem)  {
  if (elem != parent_[elem]) {
    parent_[elem] = Get(parent_[elem]);
  }
  return parent_[elem];
}

void DSU::Unite(int first, int second)  {
  first = Get(first);
  second = Get(second);
  if (first == second) {
    return;
  }
  if (rank[first] == rank[second]) {
    rank[first]++;
  }
  if (rank[first] < rank[second]) {
    parent_[first] = second;
  } else {
    parent_[second] = first;
  }
}