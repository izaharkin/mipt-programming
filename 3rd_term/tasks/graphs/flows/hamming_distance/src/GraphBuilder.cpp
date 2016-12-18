//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "GraphBuilder.h"

void InsertEdge(Graph &graph, const Edge &edge) {
  graph.AddEdge(edge);
  graph[edge.from_].push_back(graph.GetNumOfEdges() - 1);
  graph.AddEdge(Edge(edge.to_, edge.from_, 0, 0));
  graph[edge.to_].push_back(graph.GetNumOfEdges() - 1);
}

Graph GraphBuilder::BuildGraphFromStrings(const string &text, const string &pattern) noexcept {
  int text_marks_cnt = std::count(text.begin(), text.end(), '?');
  int pattern_marks_cnt = std::count(pattern.begin(), pattern.end(), '?');
  short total_length = text_marks_cnt + pattern_marks_cnt + 2;
  Graph graph(total_length);
  short source = 0;
  short target = graph.GetNumOfVertices() - 1;
  short start_index = 1;
  short cur_pos = start_index;
  for (int i = 0; i < text.length() - pattern.length() + 1; ++i) {
    short text_mark_pos = cur_pos;
    short pat_mark_pos = start_index + text_marks_cnt;
    for (int j = 0; j < pattern.length(); ++j) {
      if (text[i + j] == '?' && pattern[j] == '?') {
        InsertEdge(graph, Edge(text_mark_pos, pat_mark_pos, 1, 0));
        InsertEdge(graph, Edge(pat_mark_pos, text_mark_pos, 1, 0));
      } else if (text[i + j] == '0' && pattern[j] == '1' ||
          text[i + j] == '1' && pattern[j] == '0') {
        graph.IncreasePersistentFlow();
      } else if (text[i + j] == '0' && pattern[j] == '?') {
        InsertEdge(graph, Edge(source, pat_mark_pos, 1, 0));
      } else if (text[i + j] == '?' && pattern[j] == '0') {
        InsertEdge(graph, Edge(source, text_mark_pos, 1, 0));
      } else if (text[i + j] == '1' && pattern[j] == '?') {
        InsertEdge(graph, Edge(pat_mark_pos, target, 1, 0));
      } else if (text[i + j] == '?' && pattern[j] == '1') {
        InsertEdge(graph, Edge(text_mark_pos, target, 1, 0));
      }
      if (text[i + j] == '?') {
        text_mark_pos += 1;
      }
      if (pattern[j] == '?') {
        pat_mark_pos += 1;
      }
    }
    if (text[i] == '?') {
      cur_pos += 1;
    }
  }
  return graph;
}