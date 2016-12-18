/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_KRUSKALSTRATEGY_H
#define D_KRUSKALSTRATEGY_H

#include "Graph.h"
#include "ISpanningTreeFinderBehavior.h"
#include "DSU.h"

class KruskalStrategy : public ISpanningTreeFinderBehavior {
 public:
  virtual Graph FindMinSpanningTree(const Graph &graph) const override;
};

#endif //D_KRUSKALSTRATEGY_H
