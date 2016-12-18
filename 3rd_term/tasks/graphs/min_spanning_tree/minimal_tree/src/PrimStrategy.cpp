/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "PrimStrategy.h"

Graph PrimStrategy::FindMinSpanningTree(const Graph &graph) const noexcept {
  vector<WeightedVertex> keys;
  for (int i = 0; i < graph.GetNumOfVertices(); ++i) {
    keys.push_back(WeightedVertex(i, kInf));
  }
  // set the random vertex as a start vertex
  keys[0].weight_ = 0;
  vector<bool> used(graph.GetNumOfVertices(), false);
  vector<int> parent(graph.GetNumOfVertices(), -1);
  set<WeightedVertex> process_queue(keys.begin(), keys.end());
  while (!process_queue.empty()) {
    int current = process_queue.begin()->index_;
    process_queue.erase(process_queue.begin());
    used[current] = true;
    for (const auto &item : graph[current]) {
      int neighbour = item.index_;
      if (!used[neighbour] && item.weight_ < keys[neighbour].weight_) {
        parent[neighbour] = current;
        process_queue.erase(WeightedVertex(neighbour, keys[neighbour].weight_));
        keys[neighbour].weight_ = item.weight_;
        process_queue.insert(WeightedVertex(neighbour, keys[neighbour].weight_));
      }
    }
  }
  AdjList min_sp_tree(graph.GetNumOfVertices());
  for (int i = 0; i < graph.GetNumOfVertices(); ++i) {
    if (parent[i] != -1) {
      min_sp_tree[i].push_back(WeightedVertex(parent[i], keys[i].weight_));
    }
  }
  return Graph(min_sp_tree);
}
