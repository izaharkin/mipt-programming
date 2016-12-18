//
// Created by ilya on 25.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef FIFTEENS_PUZZLE_H
#define FIFTEENS_PUZZLE_H

class Puzzle {
 public:
  int x;
  int y;
  int digit;
  Puzzle();
  Puzzle(int _x, int _y, int _digit);
  Puzzle &operator=(const Puzzle &puzzle);
  bool operator==(const Puzzle &other_puzzle) const;
};

#endif //FIFTEENS_PUZZLE_H
