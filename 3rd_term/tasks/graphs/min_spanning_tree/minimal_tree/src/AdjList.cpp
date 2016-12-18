/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "AdjList.h"

AdjList::AdjList()
    : adj_list_(0) {}

AdjList::~AdjList()  {}

AdjList::AdjList(int size)
    : adj_list_(size) {}

AdjList::AdjList(const Matrix<WeightedVertex> &matrix)  {
  adj_list_ = matrix;
}

int AdjList::GetSize() const  {
  return adj_list_.size();
}

vector<WeightedVertex> AdjList::operator[](int vertex) const  {
  return adj_list_[vertex];
}

vector<WeightedVertex> &AdjList::operator[](int vertex)  {
  return adj_list_[vertex];
}
