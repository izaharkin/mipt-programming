/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_ISPANNINGTREEFINDERBEHAVIOR_H
#define D_ISPANNINGTREEFINDERBEHAVIOR_H

#include "Graph.h"

// Interface for different strategies
// Using ~ Strategy Pattern ~
class ISpanningTreeFinderBehavior {
 public:
  virtual Graph FindMinSpanningTree(const Graph &graph) const = 0;
  virtual ~ISpanningTreeFinderBehavior() {}
};

#endif //D_ISPANNINGTREEFINDERBEHAVIOR_H
