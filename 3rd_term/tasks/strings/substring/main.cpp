#include <iostream>

#include "src/SubstringSolver.h"

using std::cin;
using std::cout;

int main() {
  SubstringSolver solver;
  solver.Input(cin);
  solver.Run();
  solver.Output(cout);
  return 0;
}