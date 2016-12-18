#include <iostream>

#include "src/StringRestoreSolver.h"

using std::cout;
using std::cin;

int main() {
  StringRestoreSolver solver;
  solver.Input(cin);
  solver.Run();
  solver.Output(cout);
  return 0;
}