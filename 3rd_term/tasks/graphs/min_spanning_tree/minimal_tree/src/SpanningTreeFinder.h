/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_SPANNINGTREEFINDER_H
#define D_SPANNINGTREEFINDER_H

#include "Graph.h"
#include "ISpanningTreeFinderBehavior.h"

// Context
class SpanningTreeFinder {
 public:
  SpanningTreeFinder() noexcept;
  ~SpanningTreeFinder() noexcept;
  SpanningTreeFinder(const SpanningTreeFinder &) = delete;
  SpanningTreeFinder(SpanningTreeFinder &&) = delete;
  SpanningTreeFinder &operator=(const SpanningTreeFinder &) = delete;
  SpanningTreeFinder &operator=(SpanningTreeFinder &&) = delete;
  void SetGraph(const Graph &graph) noexcept;
  void FindMinimalSpanningTree(/*unique_ptr<*/ISpanningTreeFinderBehavior/*>*/ *behavior) noexcept;
  Graph GetMinimalSpanningTree() const noexcept;
 private:
  Graph graph_;
  Graph min_sp_tree_;
};

#endif //D_SPANNINGTREEFINDER_H
