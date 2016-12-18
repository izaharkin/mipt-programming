#include <fstream>
#include <iostream>

#include "src/HammingSolver.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;

int main() {
  HammingSolver solver;
  solver.Input(cin);
  solver.Run();
  solver.Output(cout);
  return 0;
}