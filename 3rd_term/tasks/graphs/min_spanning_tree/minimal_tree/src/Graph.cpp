/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "Graph.h"

Graph::Graph() noexcept
    : edges_() {}

Graph::~Graph() noexcept {}

Graph::Graph(const EdgeList &edge_list) noexcept {
  edge_list_ = EdgeList(edge_list);
}

Graph::Graph(const AdjList &adj_list) noexcept {
  edges_ = AdjList(adj_list);
}

Graph::Graph(const Matrix<WeightedVertex> &adj_list) noexcept {
  edges_ = AdjList(AdjList(adj_list));
}

void Graph::SetEdgeList(const EdgeList &edge_list) noexcept {
  edge_list_ = EdgeList(edge_list);
}

int Graph::GetNumOfVertices() const noexcept {
  return edges_.GetSize();
}

int Graph::GetNumOfEdges() const noexcept {
  return edge_list_.GetSize();
}

EdgeList Graph::GetEdgeList() const noexcept {
  return edge_list_;
}

unsigned long long int Graph::GetTotalWeight() const noexcept {
  unsigned long long int total = 0;
  if (this->edge_list_.GetSize() != 0) {
    for (int i = 0; i < edge_list_.GetSize(); ++i) {
      total += edge_list_[i].weight_;
    }
  } else {
    for (int i = 0; i < edges_.GetSize(); ++i) {
      for (int j = 0; j < edges_[i].size(); ++j) {
        total += edges_[i][j].weight_;
      }
    }
  }
  return total;
}

vector<WeightedVertex> Graph::operator[](int vertex) const noexcept {
  return edges_[vertex];
}