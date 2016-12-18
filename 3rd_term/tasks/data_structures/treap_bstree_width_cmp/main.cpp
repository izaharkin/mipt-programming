#include <iostream>

#include "src/WidthSolver.h"

using std::cin;
using std::cout;

int main() {
  WidthSolver solver;
  solver.Input(cin);
  solver.Run();
  solver.Output(cout);
  return 0;
}