/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "MinimalTreeSolver.h"

void MinimalTreeSolver::Input(istream &in_stream) noexcept {
  int num_of_vertices, num_of_edges;
  in_stream >> num_of_vertices >> num_of_edges;
  Matrix<WeightedVertex> edges(num_of_vertices);
  EdgeList edge_list;
  for (int i = 0; i < num_of_edges; ++i) {
    int b, e;
    unsigned long long int w;
    in_stream >> b >> e >> w;
    edge_list.AddEdge(Edge(b - 1, e - 1, w));
    edges[b - 1].push_back(WeightedVertex(e - 1, w));
    edges[e - 1].push_back(WeightedVertex(b - 1, w));
  }
  start_graph_ = edges;
  start_graph_.SetEdgeList(edge_list);
}

void MinimalTreeSolver::Run() noexcept {
  SpanningTreeFinder sptree_solver;
  sptree_solver.SetGraph(start_graph_);
  PrimStrategy prim_solver;
  KruskalStrategy kruskal_solver;
  sptree_solver.FindMinimalSpanningTree(&kruskal_solver);
  answer_ = sptree_solver.GetMinimalSpanningTree();
}

unsigned MinimalTreeSolver::GetMinSpanTreeWeight() const noexcept {
  return answer_.GetTotalWeight();
}

void MinimalTreeSolver::PrintAnswer(ostream &out_stream) noexcept {
  out_stream << answer_.GetTotalWeight();
}
