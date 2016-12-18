//
// Copyright (c) 2016, izaharkin. All rights reserved.
//

#ifndef FIFTEENS_TILESSOLVER_H
#define FIFTEENS_TILESSOLVER_H

#include <iostream>
#include <vector>

#include <cassert>

#include "Board.h"
#include "AStar.h"

using std::istream;
using std::ostream;
using std::vector;
using std::string;
using std::endl;

class TilesSolver {
 public:
  TilesSolver();
  void Input(istream &in_stream);
  void SetStartState(const vector<vector<int>> &vec);
  void Run();
  void PrintAnswer(ostream &out_stream) const;
  int GetLength() const;
  string GetActions() const;
 private:
  Board start_state_;
  int steps_count_;
  string actions_;
  bool incorrect_start_state_;

  bool HasSolution();
};

#endif //FIFTEENS_TILESSOLVER_H
