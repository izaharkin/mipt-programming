//
// Copyright (c) 2016, izaharkin. All rights reserved.
//

#include "Action.h"

Action::Action()
    : type_('\0'), dx_(0), dy_(0) {}

Action::Action(const Action &action_to_copy)
    : type_(action_to_copy.type_), dx_(action_to_copy.dx_), dy_(action_to_copy.dy_) {}

Action::Action(char type, int dx, int dy)
    : type_(type), dx_(dx), dy_(dy) {}

char Action::GetType() const {
  return type_;
}

int Action::GetX() const {
  return dx_;
}

int Action::GetY() const {
  return dy_;
}

vector<Action> Action::GetOrtoActions() {
  vector<Action> orto_actions;
  orto_actions.push_back(Action('U', 0, -1));
  orto_actions.push_back(Action('R', 1, 0));
  orto_actions.push_back(Action('D', 0, 1));
  orto_actions.push_back(Action('L', -1, 0));
  return orto_actions;
}

