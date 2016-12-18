#include <iostream>

#include "src/SubstringsQuantitySolver.h"

using std::cin;
using std::cout;

int main() {
  SubstringsQuantitySolver solver;
  solver.Input(cin);
  solver.Run();
  solver.Output(cout);
  return 0;
}