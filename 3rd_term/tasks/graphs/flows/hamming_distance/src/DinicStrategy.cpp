//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "DinicStrategy.h"

int DinicStrategy::FindMaxFlow(Graph &graph) noexcept {
  source_ = 0;
  target_ = graph.GetNumOfVertices() - 1;
  int maxflow = 0;
  while (RunBfsStep(graph)) {
    last_undeleted_edge_.assign(graph.GetNumOfVertices(), 0);
    int flow = RunDfsStep(graph, source_, INF);
    while (flow != 0) {
      maxflow += flow;
      flow = RunDfsStep(graph, source_, INF);
    }
  }
  return maxflow + graph.GetPersistentFlow();
}

bool DinicStrategy::RunBfsStep(Graph &graph) {
  distances_.assign(graph.GetNumOfVertices(), INF);
  distances_[source_] = 0;
  queue<short> bfs_queue({source_});
  while (!bfs_queue.empty() && distances_[target_] == INF) {
    int current = bfs_queue.front();
    bfs_queue.pop();
    for (const auto &inc_edge: graph[current]) {
      int neighbour = graph(inc_edge)->to_;
      if (graph(inc_edge)->flow_ < graph(inc_edge)->capacity_ && distances_[neighbour] == INF) {
        distances_[neighbour] = distances_[current] + 1;
        bfs_queue.push(neighbour);
      }
    }
  }
  return distances_[target_] != INF;
}

int DinicStrategy::RunDfsStep(Graph &graph, short current, int cur_min_cap) {
  if (current == target_ || cur_min_cap == 0) {
    return cur_min_cap;
  }
  while (last_undeleted_edge_[current] < graph[current].size()) {
    int v = last_undeleted_edge_[current];
    int inc_edge = graph[current][v];
    short neighbour = graph(inc_edge)->to_;
    if (distances_[neighbour] == distances_[current] + 1) {
      int can_push =
          RunDfsStep(graph, neighbour, std::min(cur_min_cap, graph(inc_edge)->capacity_ - graph(inc_edge)->flow_));
      if (can_push != 0) {
        graph(inc_edge)->flow_ += can_push;
        graph(inc_edge ^ 1)->flow_ -= can_push;
        return can_push;
      }
    }
    last_undeleted_edge_[current] += 1;
  }
  return 0;
}

pair<string, string> DinicStrategy::GetRestoredStrings(Graph &graph,
                                                       const string &text,
                                                       const string &pattern) noexcept {
  short text_marks_cnt = std::count(text.begin(), text.end(), '?');
  string res_text = text;
  string res_pat = pattern;
  short start_index = 1;
  vector<bool> min_cut(graph.GetNumOfVertices(), false);
  GetMinCutVertices(graph, source_, min_cut);
  int text_mark_pos = start_index;
  for (int i = 0; i < res_text.length(); ++i) {
    if (res_text[i] != '?') {
      continue;
    }
    if (min_cut[text_mark_pos]) {
      res_text[i] = '0';
    } else {
      res_text[i] = '1';
    }
    text_mark_pos += 1;
  }
  int pat_mark_pos = start_index + text_marks_cnt;
  for (int i = 0; i < res_pat.length(); ++i) {
    if (res_pat[i] != '?') {
      continue;
    }
    if (min_cut[pat_mark_pos]) {
      res_pat[i] = '0';
    } else {
      res_pat[i] = '1';
    }
    pat_mark_pos += 1;
  }
  return make_pair(res_text, res_pat);
}

void DinicStrategy::GetMinCutVertices(Graph &graph, int current, vector<bool> &min_cut) {
  min_cut[current] = true;
  for (const auto &inc_edge : graph[current]) {
    short neighbour = graph(inc_edge)->to_;
    if (!min_cut[neighbour] && graph(inc_edge)->capacity_ > graph(inc_edge)->flow_) {
      GetMinCutVertices(graph, neighbour, min_cut);
    }
  }
}