//
// Created by ilya on 13.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//


#include <gtest/gtest.h>

#include "../src/SecondStatisticsSolver.h"

using std::endl;
using std::vector;

TEST(SegmentTreeTests, startTest) {
  std::stringstream input_stream;
  input_stream << "10 3\n"
  "1 2 3 4 5 6 7 8 9 10\n"
  "1 2\n"
  "1 10\n"
  "2 7";

  SecondStatisticsSolver solver;
  std::stringstream answer_stream;
  solver.InputRunOutput(input_stream, answer_stream);

  vector<int> answer;
  int x;
  while (answer_stream >> x) {
    answer.push_back(x);
  }
  vector<int> true_answer({2, 2, 3});

  EXPECT_EQ(true_answer, answer);
}

TEST(SegmentTreeTests, mediumTest) {
  std::stringstream input_stream;
  input_stream << "10 8\n"
      "1 2 3 4 5 6 7 8 9 10\n"
      "1 3\n"
      "2 4\n"
      "3 5\n"
      "4 6\n"
      "5 7\n"
      "6 8\n"
      "7 9\n"
      "8 10";

  SecondStatisticsSolver solver;
  std::stringstream answer_stream;
  solver.InputRunOutput(input_stream, answer_stream);

  vector<int> answer;
  int x;
  while (answer_stream >> x) {
    answer.push_back(x);
  }
  vector<int> true_answer({2, 3, 4, 5, 6, 7, 8, 9});

  EXPECT_EQ(true_answer, answer);
}

TEST(SegmentTreeTests, oneMoreTest) {
  std::stringstream input_stream;
  input_stream << "10 3\n"
      "1 2 3 4 5 6 7 8 9 10\n"
      "1 10\n"
      "3 8\n"
      "5 6";

  SecondStatisticsSolver solver;
  std::stringstream answer_stream;
  solver.InputRunOutput(input_stream, answer_stream);

  vector<int> answer;
  int x;
  while (answer_stream >> x) {
    answer.push_back(x);
  }
  vector<int> true_answer({2, 4, 6});

  EXPECT_EQ(true_answer, answer);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}