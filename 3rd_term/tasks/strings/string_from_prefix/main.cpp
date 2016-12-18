#include <iostream>

#include "src/StringRestoringSolver.h"

using std::cout;
using std::cin;

int main() {
  StringRestoringSolver solver;
  solver.Input(cin);
  solver.Run();
  solver.Output(cout);
  return 0;
}