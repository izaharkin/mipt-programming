//
// Copyright (c) 2016, izaharkin. All rights reserved.
//

#include "Board.h"

using std::make_pair;
using std::pow;

Board::Board()
    : board_(0) {}

Board::~Board() {}

Board::Board(const Board &board_to_copy)
    : board_(board_to_copy.board_), zero_pos_(board_to_copy.zero_pos_) {}

Board::Board(const vector<Puzzle> &puzzles_state)
    : board_(puzzles_state) {}

Board::Board(int size)
    : board_(size) {}

int Board::GetSize() const {
  return board_.size();
}

int Board::GetZeroPos() const {
  return zero_pos_;
}

bool Board::LegalAction(const Action &action) const {
  bool is_legal = false;
  Puzzle cur_pos = board_[zero_pos_];
  if (0 <= cur_pos.x + action.GetX() && cur_pos.x + action.GetX() < kBoardSize &&
      0 <= cur_pos.y + action.GetY() && cur_pos.y + action.GetY() < kBoardSize) {
    is_legal = true;
  }
  return is_legal;
}

Board Board::GetBoardAfterAction(const Action &action) const {
  Board new_board(*this);
  Puzzle temp_puzzle;
  temp_puzzle.digit = new_board[zero_pos_].digit;
  if (action.GetType() == 'U') {
    new_board[zero_pos_].digit = new_board[zero_pos_ - kBoardSize].digit;
    new_board[zero_pos_ - kBoardSize].digit = temp_puzzle.digit;
    new_board.SetZeroPos(zero_pos_ - kBoardSize);
  } else if (action.GetType() == 'R') {
    new_board[zero_pos_].digit = new_board[zero_pos_ + 1].digit;
    new_board[zero_pos_ + 1].digit = temp_puzzle.digit;
    new_board.SetZeroPos(zero_pos_ + 1);
  } else if (action.GetType() == 'D') {
    new_board[zero_pos_].digit = new_board[zero_pos_ + kBoardSize].digit;
    new_board[zero_pos_ + kBoardSize].digit = temp_puzzle.digit;
    new_board.SetZeroPos(zero_pos_ + kBoardSize);
  } else if (action.GetType() == 'L') {
    new_board[zero_pos_].digit = new_board[zero_pos_ - 1].digit;
    new_board[zero_pos_ - 1].digit = temp_puzzle.digit;
    new_board.SetZeroPos(zero_pos_ - 1);
  }
  return new_board;
}

vector<pair<Board, Action>> Board::GetNeighbours() const {
  vector<pair<Board, Action>> neighbours;
  vector<Action> possible_actions = Action::GetOrtoActions();
  for (const auto &action : possible_actions) {
    if (this->LegalAction(action)) {
      Board next_board = this->GetBoardAfterAction(action);
      neighbours.push_back(make_pair(next_board, action));
    }
  }
  return neighbours;
}

long long int Board::GetHash() const {
  long long int hash_value = 0;
  for (int i = 0; i < this->GetSize(); ++i) {
    hash_value += this->board_[i].digit * pow(kBoardSize * kBoardSize, this->GetSize() - (i + 1));
  }
  return hash_value;
}

Board Board::GetIdealBoard() {
  Board ideal_board(kBoardSize * kBoardSize);
  for (int i = 0; i < ideal_board.GetSize(); ++i) {
    ideal_board[i] = Puzzle(i % kBoardSize, i / kBoardSize, (i == kBoardSize * kBoardSize - 1 ? 0 : i + 1));
  }
  ideal_board.zero_pos_ = kBoardSize * kBoardSize - 1;
  return ideal_board;
}

Puzzle &Board::operator[](int digit) {
  return board_[digit];
}

Puzzle Board::operator[](int digit) const {
  return board_[digit];
}

bool Board::operator==(const Board &second_board) const {
  return this->board_ == second_board.board_;
}

void Board::SetZeroPos(int pos) {
  zero_pos_ = pos;
}