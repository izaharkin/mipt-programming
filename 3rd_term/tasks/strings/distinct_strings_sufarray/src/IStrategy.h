//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef D_DIFFERENT_SUBSRTINGS_ISTRATEGY_H
#define D_DIFFERENT_SUBSRTINGS_ISTRATEGY_H

class IStrategy {
 public:
  virtual int GetAmountOfDifferentSubstrings(const std::string &str) = 0;
  virtual ~IStrategy() {}
};

#endif //D_DIFFERENT_SUBSRTINGS_ISTRATEGY_H
