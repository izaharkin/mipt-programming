#include <iostream>

#include "src/HeightSolver.h"

using std::cin;
using std::cout;

int main() {
  HeightSolver solver;
  solver.Input(cin);
  solver.Run();
  solver.Output(cout);
  return 0;
}