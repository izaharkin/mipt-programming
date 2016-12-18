/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_EDGE_H
#define D_EDGE_H

#include "Constants.h"

class Edge {
 public:
  int from_;
  int to_;
  unsigned long long weight_;
  Edge() ;
  Edge(int, int, unsigned long long) ;
  bool operator<(const Edge &second_edge) const ;
};

#endif //D_EDGE_H
