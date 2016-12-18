//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include <sstream>
#include <gtest/gtest.h>

#include "../src/WidthSolver.h"

using std::endl;

TEST(SubstringTests, startTest) {
  std::stringstream test_stream;
  test_stream << "10\n"
      "5 11\n"
      "18 8\n"
      "25 7\n"
      "50 12\n"
      "30 30\n"
      "15 15\n"
      "20 10\n"
      "22 5\n"
      "40 20\n"
      "45 9";
  WidthSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  int answer;
  answer_stream >> answer;
  int true_answer(1);
  EXPECT_EQ(true_answer, answer);
}

TEST(SubstringTests, simpleTest) {
  std::stringstream test_stream;
  test_stream << "10\n"
      "38 19\n"
      "37 5\n"
      "47 15\n"
      "35 0\n"
      "12 3\n"
      "0 42\n"
      "31 37\n"
      "21 45\n"
      "30 26\n"
      "41 6";
  WidthSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  int answer;
  answer_stream >> answer;
  int true_answer(1);
  EXPECT_EQ(true_answer, answer);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}