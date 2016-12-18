//
// Created by ilya on 10.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef TRADEARBITRAGE_TRADEARBITRAGESOLVER_H
#define TRADEARBITRAGE_TRADEARBITRAGESOLVER_H

#include <iostream>
#include <memory>

#include <cmath>

#include "Graph.h"


#if __cplusplus == 201402L // C++14

using std::make_unique;

#else // C++11

template < typename T, typename... CONSTRUCTOR_ARGS >
std::unique_ptr<T> make_unique( CONSTRUCTOR_ARGS&&... constructor_args )
{ return std::unique_ptr<T>( new T( std::forward<CONSTRUCTOR_ARGS>(constructor_args)... ) ); }

#endif // __cplusplus == 201402L

using std::istream;
using std::ostream;
using std::log;
using std::max;

class TradeArbitrageSolver {
 public:
  TradeArbitrageSolver();

  void Input(istream& in_stream);
  void Run();
  void PrintAnswer(ostream& out_stream) const;
 private:
  unique_ptr<Graph> graph_;
  bool answer_;
};

#endif //TRADEARBITRAGE_TRADEARBITRAGESOLVER_H
