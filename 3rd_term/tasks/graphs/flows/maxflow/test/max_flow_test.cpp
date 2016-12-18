//
// Created by ilya on 12.11.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include <sstream>
#include <gtest/gtest.h>

#include "../src/MaxFlowSolver.h"

TEST(MaxFlowTests, FirstTest) {
  MaxFlowSolver solver;
  std::stringstream test_stream;
  test_stream << "4\n 1 4 5\n 1 2 20\n 1 3 10\n 2 3 5\n 2 4 10\n 3 4 20\n 0";
  std::stringstream answer_stream;
  solver.InputRunOutput(test_stream, answer_stream);
  vector<unsigned long long int> answers;
  for (unsigned long long int cur_ans; answer_stream >> cur_ans; answers.push_back(cur_ans));
  vector<unsigned long long int> true_answers({25});
  EXPECT_EQ(answers, true_answers);
}

class DfsTest: public ::testing::Test {
 protected:
  virtual void SetUp() override {
    std::stringstream test_stream;
    test_stream << "3\n 1 3 6\n 1 2 5\n 1 2 10\n 1 2 15\n 2 3 5\n 2 3 10\n 2 3 15\n"
                   "2\n 1 2 1\n 1 2 100\n 0";
    std::stringstream answer_stream;
    MaxFlowSolver solver;
    solver.InputRunOutput(test_stream, answer_stream);
    for (unsigned long long int cur_ans; answer_stream >> cur_ans; answers.push_back(cur_ans));
  }
  vector<unsigned long long int> answers;
};

TEST_F(DfsTest, MultipleEdges) {
  vector<unsigned long long int> true_answers({30, 100});
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}