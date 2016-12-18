//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "MaxFlowFinder.h"

MaxFlowFinder::MaxFlowFinder()
    : strategy_(nullptr) {}

MaxFlowFinder::MaxFlowFinder(string &&strategy) {
  if (strategy == "dinic") {
    strategy_ = make_shared<DinicStrategy>();
  }
  // other strategies can be used, e.g. relable-to-front,
  // edmonds-karp, etc.
}

int MaxFlowFinder::FindMaxFlow
    (Graph &graph) const noexcept {
  return strategy_->FindMaxFlow(graph);
}

pair<string, string> MaxFlowFinder::GetRestoredStrings(Graph &graph,
                                                       const string &text,
                                                       const string &pattern) const noexcept {
  return strategy_->GetRestoredStrings(graph, text, pattern);
}
