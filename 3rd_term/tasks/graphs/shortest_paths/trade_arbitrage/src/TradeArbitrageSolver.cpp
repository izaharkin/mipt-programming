//
// Created by ilya on 10.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//
#include "TradeArbitrageSolver.h"

TradeArbitrageSolver::TradeArbitrageSolver()
    : graph_(make_unique<Graph>()), answer_(false) {}

void TradeArbitrageSolver::Input(istream& in_stream) {
  int num_of_vals;
  vector<Edge> edges;
  in_stream >> num_of_vals;
  for (int i = 0; i < num_of_vals; ++i) {
    for (int j = 0; j < num_of_vals; ++j) {
      if (i == j) continue;
      double cur_weight;
      in_stream >> cur_weight;
      if (cur_weight == -1) continue;
      edges.push_back(Edge(i, j, -log(cur_weight)));
    }
  }
  graph_->SetNodeCount(num_of_vals);
  graph_->SetEdges(edges);
}

bool Relax(const Edge& edge, vector<double>& distances) {
  bool relaxed = false;
  if (distances[edge.to_] > distances[edge.from_] + edge.weight_) {
    distances[edge.to_] = max(-kInf, distances[edge.from_] + edge.weight_);
    relaxed = true;
  }
  return relaxed;
}

void TradeArbitrageSolver::Run() {
  vector<Edge> edges = graph_->GetEdgeList();
  vector<double> distances(graph_->GetNodeCount(), 0.0);
  for (int i = 0; i < graph_->GetNodeCount() - 1; ++i) {
    for (const auto& edge : edges) {
      Relax(edge, distances);
    }
  }
  for (const auto& edge : edges) {
    answer_ |= Relax(edge, distances);
  }
}

void TradeArbitrageSolver::PrintAnswer(ostream &out_stream) const {
  out_stream << (answer_ ? "YES" : "NO");
}
