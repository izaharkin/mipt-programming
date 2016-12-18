//
// Created by ilya on 06.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include <sstream>
#include <gtest/gtest.h>

#include "../src/StringRestoringSolver.h"

using std::endl;

TEST(StringRestoringTests, startTest) {
  std::stringstream test_stream;
  test_stream << "0 1 2 3 0";
  StringRestoringSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  string answer;
  answer_stream >> answer;
  string true_answer("aaaab");
  EXPECT_EQ(true_answer, answer);
}

TEST(StringRestoringTests, simpleTest) {
  std::stringstream test_stream;
  test_stream << "0 0 0 0 0";
  StringRestoringSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  string answer;
  answer_stream >> answer;
  string true_answer("abbbb");
  EXPECT_EQ(true_answer, answer);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}