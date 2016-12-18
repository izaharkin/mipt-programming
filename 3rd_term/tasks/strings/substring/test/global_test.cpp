//
// Created by ilya on 05.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include <sstream>
#include <gtest/gtest.h>

#include "../src/SubstringSolver.h"

using std::endl;

TEST(SubstringTests, simpleTest) {
  std::stringstream test_stream;
  test_stream << "abb\nabbasgdkaiaabagbaabb";
  SubstringSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  vector<int> answer;
  int x;
  while (answer_stream >> x) {
    answer.push_back(x);
  }
  vector<int> true_answer({0, 17});
  EXPECT_EQ(answer, true_answer);
}

TEST(SubstringTests, oneMoreTest) {
  std::stringstream test_stream;
  test_stream << "aa\naabhdkaiaaba";
  SubstringSolver solver;
  solver.Input(test_stream);
  solver.Run();
  std::stringstream answer_stream;
  solver.Output(answer_stream);
  vector<int> answer;
  int x;
  while (answer_stream >> x) {
    answer.push_back(x);
  }
  vector<int> true_answer({0, 8});
  EXPECT_EQ(answer, true_answer);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}