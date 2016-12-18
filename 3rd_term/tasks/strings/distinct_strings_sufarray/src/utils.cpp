//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "utils.h"

size_t GetLog2(int number) {
  return static_cast<size_t>(std::floor(std::log2(number)));
}