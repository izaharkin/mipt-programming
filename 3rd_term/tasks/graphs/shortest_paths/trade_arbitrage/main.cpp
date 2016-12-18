#include "src/TradeArbitrageSolver.h"

#if __cplusplus == 201402L // C++14

using std::make_unique;

#else // C++11

template < typename T, typename... CONSTRUCTOR_ARGS >
std::unique_ptr<T> make_unique( CONSTRUCTOR_ARGS&&... constructor_args )
{ return std::unique_ptr<T>( new T( std::forward<CONSTRUCTOR_ARGS>(constructor_args)... ) ); }

#endif // __cplusplus == 201402L

using std::cout;
using std::cin;

int main() {
  TradeArbitrageSolver solver;
  solver.Input(cin);
  solver.Run();
  solver.PrintAnswer(cout);
  return 0;
}