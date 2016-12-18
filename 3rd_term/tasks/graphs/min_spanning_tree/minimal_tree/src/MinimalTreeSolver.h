/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_MINIMALTREESOLVER_H
#define D_MINIMALTREESOLVER_H

#include <iostream>

#include "Graph.h"
#include "SpanningTreeFinder.h"
#include "PrimStrategy.h"
#include "KruskalStrategy.h"

using std::istream;
using std::ostream;

class MinimalTreeSolver {
 public:
  void Input(istream &in_stream) noexcept;
  void Run() noexcept;
  unsigned GetMinSpanTreeWeight() const noexcept;
  void PrintAnswer(ostream &out_stream) noexcept;
 private:
  Graph start_graph_;
  Graph answer_;
};
#endif //D_MINIMALTREESOLVER_H
