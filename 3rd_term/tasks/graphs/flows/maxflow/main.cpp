#include <iostream>
#include <fstream>

#include "src/MaxFlowSolver.h"

using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

int main() {
  MaxFlowSolver solver;
  ifstream in_stream("input.txt");
  ofstream out_stream("output.txt");
  solver.InputRunOutput(cin, cout);
}