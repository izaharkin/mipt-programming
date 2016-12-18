//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include <sstream>
#include <gtest/gtest.h>

#include "../src/SubstringsQuantitySolver.h"

using std::endl;

TEST(SubstringsQuantityTests, startTest) {
  std::stringstream input_stream;
  input_stream << "abab";
  SubstringsQuantitySolver solver;
  solver.Input(input_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  int answer;
  answer_stream >> answer;
  int true_answer(7);
  EXPECT_EQ(true_answer, answer);
}

TEST(SubstringsQuantityTests, simpleTest) {
  std::stringstream input_stream;
  input_stream << "aaaaaaa";
  SubstringsQuantitySolver solver;
  solver.Input(input_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  int answer;
  answer_stream >> answer;
  int true_answer(7);
  EXPECT_EQ(true_answer, answer);
}

TEST(SubstringsQuantityTests, oneMoreTest) {
  std::stringstream input_stream;
  input_stream << "bcfa23aa";
  SubstringsQuantitySolver solver;
  solver.Input(input_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  int answer;
  answer_stream >> answer;
  int true_answer(34);
  EXPECT_EQ(true_answer, answer);
}

TEST(SubstringsQuantityTests, yetAnotherTest) {
  std::stringstream input_stream;
  input_stream << "abbaabac";
  SubstringsQuantitySolver solver;
  solver.Input(input_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  int answer;
  answer_stream >> answer;
  int true_answer(29);
  EXPECT_EQ(true_answer, answer);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}