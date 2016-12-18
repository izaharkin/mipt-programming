/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "SpanningTreeFinder.h"

SpanningTreeFinder::SpanningTreeFinder() noexcept
    : graph_(), min_sp_tree_() {}

SpanningTreeFinder::~SpanningTreeFinder() noexcept {}

void SpanningTreeFinder::SetGraph(const Graph &graph) noexcept {
  graph_ = graph;
}

void SpanningTreeFinder::FindMinimalSpanningTree(/*unique_ptr<*/ISpanningTreeFinderBehavior/*>*/ *behavior) noexcept {
  /*unique_ptr<*/ISpanningTreeFinderBehavior/*>*/ *sp_tree_finder = /*std::move(*/behavior/*)*/;
  min_sp_tree_ = sp_tree_finder->FindMinSpanningTree(graph_);
}

Graph SpanningTreeFinder::GetMinimalSpanningTree() const noexcept {
  return min_sp_tree_;
}
