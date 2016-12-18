//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "RelableToFrontStrategy.h"

void RelableToFrontStrategy::Initialize(const Graph &graph, int start, int end) noexcept {
  n_ = graph.GetNumOfVertices();
  EdgeList edges = graph.GetEdgeList();
  capacity_.resize(n_, vector<double>(n_, 0));
  neighbours_.resize(n_, vector<int>(n_, 0));
  for (int i = 0; i < edges.GetSize(); ++i) {
    capacity_[edges[i].from_][edges[i].to_] += edges[i].weight_;
    capacity_[edges[i].to_][edges[i].from_] += edges[i].weight_;
    neighbours_[edges[i].from_].push_back(edges[i].to_);
    neighbours_[edges[i].to_].push_back(edges[i].from_);
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
    excess_flow_[i] = capacity_[start][i];
    excess_flow_[start] -= capacity_[start][i];
  }
}

void RelableToFrontStrategy::Push(int u, int v) noexcept {
  double delta = min(excess_flow_[u], capacity_[u][v] - flow_[u][v]);
  flow_[u][v] += delta;
  flow_[v][u] = -flow_[u][v];
  excess_flow_[u] -= delta;
  excess_flow_[v] += delta;
}

void RelableToFrontStrategy::Relable(int u) noexcept {
  int min_height;
  for (int v = 0; v < n_; ++v) {
    if (capacity_[u][v] - flow_[u][v] > 0) {
      min_height = min(min_height, height_[v]);
    }
  }
  height_[u] = min_height + 1;
}

void RelableToFrontStrategy::Discharge(int u) noexcept {
  while (excess_flow_[u] > 0) {
    int v;
    if (current_[u] != neighbours_[u].end()) {
      v = *current_[u];
    }
    if (current_[u] == neighbours_[u].end()) {
      Relable(u);
      current_[u] = neighbours_[u].begin();
    } else if (capacity_[u][v] - flow_[u][v] > 0 && height_[u] == height_[v] + 1) {
      Push(u, v);
    } else {
      current_[u] += 1;
    }
  }
}

double RelableToFrontStrategy::findMaxFlow(const Graph &graph, int start, int end) noexcept {
  double max_flow = 0.0;
  Initialize(graph, start, end);
  list<int> vlist;
  for (int i = 0; i < n_; ++i) {
    if (i == start || i == end) {
      continue;
    }
    vlist.push_back(i);
  }
  current_.resize(n_);
  for (int i = 0; i < n_; ++i) {
    if (i == start || i == end) {
      continue;
    }
    current_[i] = neighbours_[i].begin();
  }
  vlist.push_back(kInf);
  // algorithm
  int u = vlist.front();
  while (u != kInf) {
    int old_height = height_[u];
    Discharge(u);
    if (height_[u] > old_height) {
      vlist.remove(u);
      vlist.push_front(u);
    }
    bool flag_next = false;
    for (auto item : vlist) {
      if (flag_next) {
        u = item;
        break;
      }
      if (item == u) {
        flag_next = true;
      }
    }
  }
  // calculate the result
  for (int i = 0; i < n_; ++i) {
    max_flow += flow_[start][i];
  }
  return max_flow;
}