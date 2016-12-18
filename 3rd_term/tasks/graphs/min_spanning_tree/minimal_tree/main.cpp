#include <iostream>
#include <fstream>

#include "src/MinimalTreeSolver.h"

using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

int main() {
  MinimalTreeSolver solver;
  ifstream in_stream("kruskal.in");
  ofstream out_stream("kruskal.out");
  solver.Input(in_stream);
  solver.Run();
  solver.PrintAnswer(out_stream);
  return 0;
}