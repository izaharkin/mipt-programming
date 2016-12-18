//
// Copyright (c) 2016, izaharkin. All rights reserved.
//

#ifndef FIFTEENS_ASTAR_H
#define FIFTEENS_ASTAR_H

#include <functional>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#include "Board.h"

using std::priority_queue;
using std::function;
using std::reverse;
using std::string;
using std::fabs;
using std::map;
using std::set;

class AStar {
 public:
  AStar();
  ~AStar();
  AStar(const AStar &) = delete;
  AStar(AStar &&) = delete;
  AStar &operator=(const AStar &) = delete;
  AStar &operator=(AStar &&) = delete;
  void SetHeuristic(function<double(const Board &, const Board &)> heuristic);
  void SetStartState(const Board &state);
  void SetEndState(const Board &state);
  void FindSolution();
  string GetRightActions() const;
 private:
  function<double(const Board &, const Board &)> heuristic_;
  Board start_state_;
  Board end_state_;
  string actions_;
};

double manhattan_puzzles(const Puzzle &first, const Puzzle &second);
double manhattan_boards(const Board &first, const Board &second);

class AStarItem {
 public:
  Board board_;
  int step_;
  double func_val_;
  char from_action_;
  long long int parent_;
  AStarItem();
  AStarItem(const Board &, int, double, char, long long int);
  bool operator<(const AStarItem &second_item) const;
};

#endif //FIFTEENS_ASTAR_H
