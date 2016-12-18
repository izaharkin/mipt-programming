//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef F_HAMMING_DINICSTRATEGY_H
#define F_HAMMING_DINICSTRATEGY_H

#include <algorithm>
#include <queue>
#include <vector>

#include "constants.h"
#include "Graph.h"
#include "IStrategy.h"

using std::queue;
using std::string;
using std::vector;

class DinicStrategy : public IStrategy {
 public:
  int FindMaxFlow(Graph &graph) noexcept override;
  pair<string, string> GetRestoredStrings(Graph &graph, const string &text, const string &pattern) noexcept override;
 private:
  short source_;
  short target_;
  vector<short> distances_;
  vector<int> last_undeleted_edge_;
  bool RunBfsStep(Graph &graph);
  int RunDfsStep(Graph &graph, short vertex, int cur_min_cap);
  void GetMinCutVertices(Graph &graph, int current, vector<bool> &min_cut);
};

#endif //F_HAMMING_DINICSTRATEGY_H
