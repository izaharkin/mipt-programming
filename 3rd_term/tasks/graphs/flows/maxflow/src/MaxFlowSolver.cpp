//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "MaxFlowSolver.h"

void MaxFlowSolver::InputRunOutput(istream &in, ostream &out) {
  int num_of_vertices;
  in >> num_of_vertices;
  do {
    int start_vertex, end_vertex;
    int num_of_edges;
    in >> start_vertex >> end_vertex >> num_of_edges;
    vector<Edge> edges;
    for (int i = 0; i < num_of_edges; ++i) {
      int from, to;
      double capacity;
      in >> from >> to >> capacity;
      edges.push_back(Edge(from - 1, to - 1, capacity));
    }
    graph_ = EdgeList(edges);
    graph_.SetNumOfVertices(num_of_vertices);
    // Run()
    MaxFlowFinder finder;
    finder.SetGraph(graph_);
    PushRelableStrategy preflow_solver;
    RelableToFrontStrategy front_solver;
    finder.FindMaxFlow(&front_solver, start_vertex - 1, end_vertex - 1);
    double max_flow = finder.GetMaxFlowValue();
    // Output()
    out << (unsigned long long int) max_flow << endl;
    // Input()
    in >> num_of_vertices;
  } while (num_of_vertices != 0);
}
