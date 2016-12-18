/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "KruskalStrategy.h"

Graph KruskalStrategy::FindMinSpanningTree(const Graph &graph) const {
  EdgeList edges = graph.GetEdgeList();
  edges.SortByWeight();
  DSU trees(graph.GetNumOfVertices());
  EdgeList min_sp_tree;
  for (int i = 0; i < edges.GetSize(); ++i) {
    Edge current_edge = edges[i];
    if (trees.Get(current_edge.from_) != trees.Get(current_edge.to_)) {
      min_sp_tree.AddEdge(current_edge);
      trees.Unite(current_edge.from_, current_edge.to_);
    }
  }
  return Graph(min_sp_tree);
}
