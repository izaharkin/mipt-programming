/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */
#include "gtest/gtest.h"
#include "../src/MinimalTreeSolver.h"

TEST(basic_test, simple_test) {
  MinimalTreeSolver solver;
  std::stringstream ss;
  ss << 4 << ' ' << 4 << ' '
     << 1 << ' ' << 2 << ' ' << 1 << ' '
     << 2 << ' ' << 3 << ' ' << 2 << ' '
     << 3 << ' ' << 4 << ' ' << 5 << ' '
     << 4 << ' ' << 1 << ' ' << 4;
  solver.Input(ss);
  solver.Run();
  unsigned long long answer = solver.GetMinSpanTreeWeight();
  EXPECT_EQ(answer, 7);
}

TEST(basic_test, multiple_edges) {
  MinimalTreeSolver solver;
  std::stringstream ss;
  ss << 4 << ' ' << 8 << ' '
     << 1 << ' ' << 1 << ' ' << 100 << ' '
     << 1 << ' ' << 2 << ' ' << 5 << ' '
     << 1 << ' ' << 2 << ' ' << 15 << ' '
     << 2 << ' ' << 3 << ' ' << 25 << ' '
     << 3 << ' ' << 2 << ' ' << 5 << ' '
     << 3 << ' ' << 4 << ' ' << 30 << ' '
     << 4 << ' ' << 1 << ' ' << 0 << ' '
     << 4 << ' ' << 1 << ' ' << 5;
  solver.Input(ss);
  solver.Run();
  unsigned long long answer = solver.GetMinSpanTreeWeight();
  EXPECT_EQ(answer, 10);
}

TEST(basic_test, one_more_test) {
  MinimalTreeSolver solver;
  std::stringstream ss;
  ss << 4 << ' ' << 5 << ' '
     << 1 << ' ' << 3 << ' ' << 1000 << ' '
     << 4 << ' ' << 2 << ' ' << 15 << ' '
     << 2 << ' ' << 3 << ' ' << 10 << ' '
     << 3 << ' ' << 2 << ' ' << 15 << ' '
     << 2 << ' ' << 3 << ' ' << 25 << ' ';
  solver.Input(ss);
  solver.Run();
  unsigned long long answer = solver.GetMinSpanTreeWeight();
  EXPECT_EQ(answer, 1025);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}