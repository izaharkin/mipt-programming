/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_EDGELIST_H
#define D_EDGELIST_H

#include <algorithm>
#include <vector>

#include "Edge.h"

using std::vector;

class EdgeList {
 public:
  EdgeList() ;
  ~EdgeList() ;
  void AddEdge(const Edge &edge) ;
  int GetSize() const ;
  void SortByWeight() ;
  Edge operator[](int index) const ;
 private:
  vector<Edge> edge_list_;
};

#endif //D_EDGELIST_H
