//
// Copyright (c) 2016, izaharkin. All rights reserved.
//

#ifndef FIFTEENS_ACTION_H
#define FIFTEENS_ACTION_H

#include <vector>

using std::vector;

class Action {
 public:
  Action();
  Action(const Action &action_to_copy);
  Action(char type, int dx, int dy);
  char GetType() const;
  int GetX() const;
  int GetY() const;
  static vector<Action> GetOrtoActions();
 private:
  char type_;
  int dx_;
  int dy_;
};

#endif //FIFTEENS_ACTION_H
