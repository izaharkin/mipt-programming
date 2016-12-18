/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_PRIMSTRATEGY_H
#define D_PRIMSTRATEGY_H

#include <set>

#include "Graph.h"
#include "Constants.h"
#include "ISpanningTreeFinderBehavior.h"

using std::set;

class PrimStrategy : public ISpanningTreeFinderBehavior {
 public:
  virtual Graph FindMinSpanningTree(const Graph &graph) const noexcept override;
};


#endif //D_PRIMSTRATEGY_H
