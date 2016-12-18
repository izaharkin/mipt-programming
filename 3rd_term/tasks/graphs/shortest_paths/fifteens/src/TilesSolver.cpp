//
// Copyright (c) 2016, izaharkin. All rights reserved.
//

#include "TilesSolver.h"

TilesSolver::TilesSolver()
    : start_state_(), steps_count_(0), actions_(""), incorrect_start_state_(false) {}

void TilesSolver::Input(istream &in_stream) {
  start_state_ = Board(kBoardSize * kBoardSize);
  int number = -1;
  for (int i = 0; i < kBoardSize * kBoardSize; ++i) {
    in_stream >> number;
    if (number == 0) {
      start_state_.SetZeroPos(i);
    }
    start_state_[i] = Puzzle(i % kBoardSize, i / kBoardSize, number);
  }
}

void TilesSolver::SetStartState(const vector<vector<int>> &vec) {
  start_state_ = Board(kBoardSize * kBoardSize);
  int k = 0;
  for (int i = 0; i < kBoardSize; ++i) {
    for (int j = 0; j < kBoardSize; ++j) {
      // handle incorrect board
      if (!(0 <= vec[i][j] && vec[i][j] < kBoardSize * kBoardSize)) {
        steps_count_ = -1;
        incorrect_start_state_ = true;
        return;
      }
      start_state_[k++] = Puzzle(j, i, vec[i][j]);
      if (vec[i][j] == 0) {
        start_state_.SetZeroPos(i * 3 + j);
      }
    }
  }
}

int Board::GetInversionsCount() const {
  int inversions = 0;
  for (int i = 0; i < this->GetSize(); ++i) {
    if (this->board_[i].digit == 0) {
      continue;
    }
    for (int j = i + 1; j < this->GetSize(); ++j) {
      if (this->board_[j].digit == 0) {
        continue;
      }
      if (this->board_[j].digit < this->board_[i].digit) {
        inversions += 1;
      }
    }
  }
  return inversions;
}

bool TilesSolver::HasSolution() {
  bool has_solution = false;
  int inversions = start_state_.GetInversionsCount();
  int row_with_blink_puzzle = start_state_[start_state_.GetZeroPos()].y;
  if (kBoardSize % 2 == 0) {
    has_solution = (row_with_blink_puzzle % 2 == 0 && inversions % 2 == 1)
        || (row_with_blink_puzzle % 2 == 1 && inversions % 2 == 0); // it can be XOR
  } else {
    has_solution = (inversions % 2 == 0);
  }
  return has_solution;
}

void TilesSolver::Run() {
  if (incorrect_start_state_) {
    return;
  }
  if (!this->HasSolution()) {
    steps_count_ = -1;
  } else {
    AStar astar_solver;
    astar_solver.SetHeuristic(manhattan_boards);
    astar_solver.SetStartState(start_state_);
    astar_solver.SetEndState(Board::GetIdealBoard());
    astar_solver.FindSolution();
    actions_ = astar_solver.GetRightActions();
    steps_count_ = actions_.size();
  }
}

void TilesSolver::PrintAnswer(ostream &out_stream) const {
  out_stream << steps_count_;
  if (steps_count_ > 0) {
    out_stream << endl << actions_;
  }
}

int TilesSolver::GetLength() const {
  return steps_count_;
}

string TilesSolver::GetActions() const {
  return actions_;
}