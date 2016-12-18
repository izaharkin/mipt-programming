//
// Copyright (c) 2016, izaharkin. All rights reserved.
//

#include "AStar.h"

double manhattan_puzzles(const Puzzle &first, const Puzzle &second) {
  return (fabs(second.x - first.x) + fabs(second.y - first.y));
}

double manhattan_boards(const Board &first, const Board &second) {
  int res_diff = 0;
  for (int i = 0; i < first.GetSize(); ++i) {
    int ind;
    if (first[i].digit == 0) {
      ind = first.GetSize() - 1;
    } else {
      ind = first[i].digit - 1;
    }
    res_diff += manhattan_puzzles(first[i], second[ind]);
  }
  return res_diff;
}

AStar::AStar()
    : heuristic_(), start_state_(), end_state_(), actions_("") {}

AStar::~AStar() {}

void AStar::SetHeuristic(function<double(const Board &, const Board &)> heuristic) {
  heuristic_ = heuristic;
}

void AStar::SetStartState(const Board &state) {
  start_state_ = state;
}

void AStar::SetEndState(const Board &state) {
  end_state_ = state;
}

AStarItem::AStarItem()
    : board_(), step_(0), func_val_(0.0), from_action_('\0'), parent_(-1) {}

AStarItem::AStarItem(const Board &_board, int new_step, double _func_val, char _from_action, long long int new_parent)
    : board_(_board), step_(new_step), func_val_(_func_val), from_action_(_from_action), parent_(new_parent) {}

bool AStarItem::operator<(const AStarItem &second_item) const {
  return this->func_val_ > second_item.func_val_;
}

void AStar::FindSolution() {
  priority_queue<AStarItem> boards_queue;
  map<long long int, AStarItem> right_moves;
  set<long long int> visited;
  AStarItem current(start_state_, 1, 1 + heuristic_(start_state_, end_state_), '#', -1);
  boards_queue.push(current);
  right_moves[current.board_.GetHash()] = current;
  AStarItem state = current;
  while (!boards_queue.empty()) {
    current = boards_queue.top();
    boards_queue.pop();
    long long int cur_hash = (current.board_).GetHash();
    visited.insert(cur_hash);
    if (current.board_ == end_state_) {
      state = current;
      break;
    }
    for (const auto &neighbour : (current.board_).GetNeighbours()) {
      Board next_board = neighbour.first;
      Action next_action = neighbour.second;
      int next_step = right_moves[cur_hash].step_ + 1;
      double next_func_val = next_step + heuristic_(next_board, end_state_);
      long long int next_board_hash = next_board.GetHash();
      auto iter = right_moves.find(next_board_hash);
      if (visited.find(next_board_hash) == visited.end() ||
          iter != right_moves.end() && iter->second.step_ > next_step) {
        right_moves.erase(next_board_hash);
        AStarItem next_state(next_board, next_step, next_func_val, next_action.GetType(), cur_hash);
        right_moves[next_board_hash] = next_state;
        boards_queue.push(next_state);
      }
    }
  }
  actions_ = "";
  while (state.parent_ != -1) {
    actions_ += state.from_action_;
    state = right_moves[state.parent_];
  }
  reverse(actions_.begin(), actions_.end());
}

string AStar::GetRightActions() const {
  return actions_;
}