//
// Created by ilya on 10.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef TRADEARBITRAGE_EDGE_H
#define TRADEARBITRAGE_EDGE_H

#include "constants.h"

class Edge {
 public:
  int from_;
  int to_;
  double weight_;
  Edge();
  Edge(int, int, double);
};

#endif //TRADEARBITRAGE_EDGE_H
