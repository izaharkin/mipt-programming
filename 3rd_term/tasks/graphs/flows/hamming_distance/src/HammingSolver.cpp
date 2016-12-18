//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "HammingSolver.h"

void HammingSolver::Input(istream &in) {
  in >> text_ >> pattern_;
}

void HammingSolver::Run() {
  Graph graph = GraphBuilder::BuildGraphFromStrings(text_, pattern_);
  MaxFlowFinder flow_finder("dinic");
  int max_flow = flow_finder.FindMaxFlow(graph);
  pair<string, string> results = flow_finder.GetRestoredStrings(graph, text_, pattern_);
  min_dist_ = max_flow;
  result_text_ = results.first;
  result_pat_ = results.second;
}

void HammingSolver::Output(ostream &out) const {
  out << min_dist_ << endl;
  out << result_text_ << endl << result_pat_;
}