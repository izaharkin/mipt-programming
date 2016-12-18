/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_GRAPH_H
#define D_GRAPH_H

#include <memory>

#include "WeightedVertex.h"
#include "EdgeList.h"
#include "AdjList.h"

using std::make_unique;
using std::unique_ptr;

class Graph {
 public:
  Graph() noexcept;
  ~Graph() noexcept;
  Graph(const EdgeList &edge_list) noexcept;
  Graph(const AdjList &adj_list) noexcept;
  Graph(const Matrix<WeightedVertex> &adj_list) noexcept;
  void SetEdgeList(const EdgeList &edge_list) noexcept;
  int GetNumOfVertices() const noexcept;
  int GetNumOfEdges() const noexcept;
  EdgeList GetEdgeList() const noexcept;
  unsigned long long int GetTotalWeight() const noexcept;
  vector<WeightedVertex> operator[](int vertex) const noexcept;
 private:
  AdjList edges_;
  EdgeList edge_list_;
};

#endif //D_GRAPH_H
