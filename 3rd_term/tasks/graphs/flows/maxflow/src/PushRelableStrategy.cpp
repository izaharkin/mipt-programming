//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "PushRelableStrategy.h"

void PushRelableStrategy::Initialize(const Graph &graph, int start, int end) noexcept {
  n_ = graph.GetNumOfVertices();
  EdgeList edges = graph.GetEdgeList();
  capacity_.resize(n_, vector<double>(n_, 0));
  for (int i = 0; i < edges.GetSize(); ++i) {
    capacity_[edges[i].from_][edges[i].to_] = edges[i].weight_;
    capacity_[edges[i].to_][edges[i].from_] = edges[i].weight_;
  }
  flow_.resize(n_, vector<double>(n_, 0));
  for (int i = 0; i < n_; ++i) {
    if (i == start) {
      continue;
    }
    flow_[start][i] = capacity_[start][i];
    flow_[i][start] = -capacity_[start][i];
  }
  height_.resize(n_, 0);
  height_[start] = n_;
  excess_flow_.resize(n_);
  for (int i = 0; i < n_; ++i) {
    if (i == start) {
      continue;
    }
    excess_flow_[i] = flow_[start][i];
  }
}

void PushRelableStrategy::Push(int u, int v) noexcept {
  double delta = min(excess_flow_[u], capacity_[u][v] - flow_[u][v]);
  flow_[u][v] += delta;
  flow_[v][u] = -flow_[u][v];
  excess_flow_[u] -= delta;
  excess_flow_[v] += delta;
}

void PushRelableStrategy::Relable(int u) noexcept {
  int min_height = kInf;
  for (int v = 0; v < n_; ++v) {
    if (capacity_[u][v] - flow_[u][v] > 0) {
      min_height = min(min_height, height_[v]);
    }
  }
  if (min_height == kInf) {
    return;
  }
  height_[u] = min_height + 1;
}

double PushRelableStrategy::findMaxFlow(const Graph &graph, int start, int end) noexcept {
  double max_flow = 0.0;
  Initialize(graph, start, end);
  while (true) {
    int u, v;
    for (u = 0; u < n_; ++u) {
      if (u == start) {
        continue;
      }
      if (excess_flow_[u] > 0) {
        break;
      }
    }
    if (u == end) {
      break;
    }
    for (v = 0; v < n_; ++v) {
      if (capacity_[u][v] - flow_[u][v] > 0 && height_[u] == height_[v] + 1) {
        break;
      }
    }
    if (v < n_) {
      Push(u, v);
    } else {
      Relable(u);
    }
  }
  // calculate the result
  for (int i = 0; i < n_; ++i) {
    max_flow += flow_[start][i];
  }
  return max_flow;
}