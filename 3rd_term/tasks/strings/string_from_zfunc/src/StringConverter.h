//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef B2_FROM_ZFUNCTION_STRINGCONVERTER_H
#define B2_FROM_ZFUNCTION_STRINGCONVERTER_H

#include <string>
#include <vector>

#include "constants.h"
#include "StringFunctions.h"

using std::string;
using std::vector;

class StringConverter {
 public:
  StringConverter() = delete;
  StringConverter(const StringConverter &) = delete;
  StringConverter(StringConverter &&) = delete;

  static string GetStringFromPrefixFunction(const vector<int> &prefix_values);
  static vector<int> GetPrefixFunctionFromZFunction(const vector<int> &z_values);
  static string GetStringFromZFunction(const vector<int> &z_values);
};

#endif //B2_FROM_ZFUNCTION_STRINGCONVERTER_H
