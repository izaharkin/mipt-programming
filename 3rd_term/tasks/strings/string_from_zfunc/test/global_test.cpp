//
// Created by ilya on 06.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include <sstream>
#include <gtest/gtest.h>

#include "../src/StringRestoreSolver.h"

using std::endl;

TEST(StringRestoreTests, startTest) {
  std::stringstream test_stream;
  test_stream << "5 3 2 1 0";
  StringRestoreSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  string answer;
  answer_stream >> answer;
  string true_answer("aaaab");
  EXPECT_EQ(true_answer, answer);
}

TEST(StringRestoreTests, simpleTest) {
  std::stringstream test_stream;
  test_stream << "4 0 0 0";
  StringRestoreSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  string answer;
  answer_stream >> answer;
  string true_answer("abbb");
  EXPECT_EQ(true_answer, answer);
}

TEST(StringRestoreTests, oneMoreTest) {
  std::stringstream test_stream;
  test_stream << "6 1 0 3 0 0";
  StringRestoreSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  string answer;
  answer_stream >> answer;
  string true_answer("aabaab");
  EXPECT_EQ(true_answer, answer);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}