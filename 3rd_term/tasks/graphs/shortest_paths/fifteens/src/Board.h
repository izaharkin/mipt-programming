//
// Copyright (c) 2016, izaharkin. All rights reserved.
//

#ifndef FIFTEENS_BOARD_H
#define FIFTEENS_BOARD_H

#include <cmath>

#include "Action.h"
#include "Puzzle.h"

using std::pair;

const int kBoardSize = 3;

class Board {
 public:
  Board();
  ~Board();
  Board(const Board &board);
  Board(const vector<Puzzle> &puzzles_state);
  Board(int size);
  int GetSize() const;
  int GetZeroPos() const;
  bool LegalAction(const Action &action) const;
  Board GetBoardAfterAction(const Action &action) const;
  vector<pair<Board, Action>> GetNeighbours() const;
  long long int GetHash() const;
  static Board GetIdealBoard();
  int GetInversionsCount() const;
  void SetZeroPos(int pos);
  Puzzle &operator[](int digit);
  Puzzle operator[](int digit) const;
  bool operator==(const Board &second_board) const;
 private:
  vector<Puzzle> board_;
  int zero_pos_;
};

#endif //FIFTEENS_BOARD_H
