//
// Created by ilya on 04.12.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include <sstream>

#include "../src/HammingSolver.h"
#include <gtest/gtest.h>

TEST(HammingTests, firstTest) {
  HammingSolver solver;

  std::stringstream test_stream;
  test_stream << "00?\n1?";
  solver.Input(test_stream);

  solver.Run();

  std::stringstream answer_stream;
  solver.Output(answer_stream);

  int answer;
  answer_stream >> answer;
  int true_answer = 2;
  string true_text = "000";
  string text;
  answer_stream >> text;
  string true_pattern = "10";
  string pattern;
  answer_stream >> pattern;

  EXPECT_EQ(true_answer, answer);
  EXPECT_EQ(true_text, text);
  EXPECT_EQ(true_pattern, pattern);
}

TEST(HammingTests, secondTest) {
  HammingSolver solver;

  std::stringstream test_stream;
  test_stream << "10000000\n??";
  solver.Input(test_stream);

  solver.Run();

  std::stringstream answer_stream;
  solver.Output(answer_stream);

  int answer;
  answer_stream >> answer;
  int true_answer = 1;
  string true_text = "10000000";
  string text;
  answer_stream >> text;
  string true_pattern = "00";
  string pattern;
  answer_stream >> pattern;

  EXPECT_EQ(true_answer, answer);
  EXPECT_EQ(true_text, text);
  EXPECT_EQ(true_pattern, pattern);
}

TEST(HammingTests, longStringTest) {
  HammingSolver solver;

  std::stringstream test_stream;
  test_stream << "10101010010101111111111001011?????????????????101010101??????????????????????????11001010101010101001??????????????????10101010100101????????10101010100101???????100010110101011011100101001????????1001010?0?1?10011????????\n??101010??????1010?????????";
  solver.Input(test_stream);

  solver.Run();

  std::stringstream answer_stream;
  solver.Output(answer_stream);

  int answer;
  answer_stream >> answer;
  int true_answer = 1835;
  string true_text = "101010100101011111111110010111111111111111111110101010111111111111111111111111111110010101010101010011111111111111111111010101010010111111111101010101001011111111100010110101011011100101001111111111001010101111001111111111";
  string text;
  answer_stream >> text;
  string true_pattern = "111010101111111010111111111";
  string pattern;
  answer_stream >> pattern;

  EXPECT_EQ(true_answer, answer);
  EXPECT_EQ(true_text, text);
  EXPECT_EQ(true_pattern, pattern);
}

TEST(HammingTests, manyQuestionMarksTest) {
  HammingSolver solver;

  std::stringstream test_stream;
  test_stream << "?????????????????????????????????????????????????????????????????10101??????????????????????????????????????????????????????????????????????????1\n??????????????????????";
  solver.Input(test_stream);

  solver.Run();

  std::stringstream answer_stream;
  solver.Output(answer_stream);

  int answer;
  answer_stream >> answer;
  int true_answer = 44;
  string true_text = "1111111111111111111111111111111111111111111111111111111111111111110101111111111111111111111111111111111111111111111111111111111111111111111111111";
  string text;
  answer_stream >> text;
  string true_pattern = "1111111111111111111111";
  string pattern;
  answer_stream >> pattern;

  EXPECT_EQ(true_answer, answer);
  EXPECT_EQ(true_text, text);
  EXPECT_EQ(true_pattern, pattern);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}