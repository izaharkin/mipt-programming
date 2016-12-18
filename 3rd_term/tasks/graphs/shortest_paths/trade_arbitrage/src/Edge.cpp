//
// Created by ilya on 10.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//
#include "Edge.h"

Edge::Edge()
    : from_(0), to_(0), weight_(-kInf) {}

Edge::Edge(int from, int to, double weight)
    : from_(from), to_(to), weight_(weight) {}

