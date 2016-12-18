//
// Created by ilya on 25.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "Puzzle.h"

Puzzle::Puzzle()
    : x(0), y(0), digit(-1) {}

Puzzle::Puzzle(int _x, int _y, int _digit)
    : x(_x), y(_y), digit(_digit) {}

Puzzle &Puzzle::operator=(const Puzzle &puzzle) {
  this->x = puzzle.x;
  this->y = puzzle.y;
  this->digit = puzzle.digit;
  return *this;
}

bool Puzzle::operator==(const Puzzle &other_puzzle) const {
  return this->digit == other_puzzle.digit;
}