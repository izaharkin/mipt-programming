/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "EdgeList.h"

EdgeList::EdgeList()
    : edge_list_(0) {}

EdgeList::~EdgeList()  {}

void EdgeList::AddEdge(const Edge &edge)  {
  edge_list_.push_back(edge);
}

int EdgeList::GetSize() const  {
  return edge_list_.size();
}

void EdgeList::SortByWeight()  {
  sort(edge_list_.begin(), edge_list_.end(),
       [](Edge first, Edge second) {
         return first.weight_ < second.weight_;
       });
}

Edge EdgeList::operator[](int index) const  {
  return edge_list_[index];
}