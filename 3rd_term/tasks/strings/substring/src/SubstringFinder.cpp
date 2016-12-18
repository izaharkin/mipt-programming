//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "SubstringFinder.h"

SubstringFinder::SubstringFinder()
    : strategy_(nullptr) {}

SubstringFinder::SubstringFinder(string &&strategy_name) {
  if (strategy_name == "KMP") {
    strategy_ = make_shared<KMPStrategy>();
  }
}

vector<int> SubstringFinder::GetAllEntrances(const string &text, const string &pattern) {
  return strategy_->GetSubstringEntrances(text, pattern);
}