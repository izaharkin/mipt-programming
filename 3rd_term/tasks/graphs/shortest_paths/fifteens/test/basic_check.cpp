//
// Copyright (c) 2016, izaharkin. All rights reserved.
//
#include <sstream>
#include <gtest/gtest.h>

#include "../src/TilesSolver.h"

TEST(basic__Test, StartStateEqualsEndStateTest) {
  TilesSolver solver;
  std::stringstream ss;
  ss << 1 << ' ' << 2 << ' ' << 3 << ' '
     << 4 << ' ' << 5 << ' ' << 6 << ' '
     << 7 << ' ' << 8 << ' ' << 0;
  vector<vector<int>> puzzles(kBoardSize, vector<int>(kBoardSize));
  for (int i = 0; i < kBoardSize; ++i) {
    for (int j = 0; j < kBoardSize; ++j) {
      ss >> puzzles[i][j];
    }
  }
  solver.SetStartState(puzzles);
  solver.Run();
  int steps_count = solver.GetLength();
  EXPECT_EQ(steps_count, 0);
}

// @Test
TEST(basic__Test, IncorrectStartStateTest) {
  TilesSolver solver;
  vector<vector<int>> puzzles(kBoardSize, vector<int>(kBoardSize));
  for (int i = 0; i < kBoardSize; ++i) {
    for (int j = 0; j < kBoardSize; ++j) {
      puzzles[i][j] = i * 3 + j + 1;
    }
  }
  solver.SetStartState(puzzles);
  solver.Run();
  int steps_count = solver.GetLength();
  EXPECT_EQ(steps_count, -1);
}

// @Test
TEST(basic__Test, NoSolutionTest) {
  TilesSolver solver;
  std::stringstream ss;
  ss << 1 << ' ' << 2 << ' ' << 3 << ' '
     << 8 << ' ' << 0 << ' ' << 4 << ' '
     << 7 << ' ' << 6 << ' ' << 5;
  vector<vector<int>> puzzles(kBoardSize, vector<int>(kBoardSize));
  for (int i = 0; i < kBoardSize; ++i) {
    for (int j = 0; j < kBoardSize; ++j) {
      ss >> puzzles[i][j];
    }
  }
  solver.SetStartState(puzzles);
  solver.Run();
  int steps_count = solver.GetLength();
  EXPECT_EQ(steps_count, -1);
}

// @Test
TEST(basic__Test, RightSolution1Test) {
  TilesSolver solver;
  std::stringstream ss;
  ss << 0 << ' ' << 1 << ' ' << 2 << ' '
     << 3 << ' ' << 4 << ' ' << 5 << ' '
     << 6 << ' ' << 7 << ' ' << 8;
  vector<vector<int>> puzzles(kBoardSize, vector<int>(kBoardSize));
  for (int i = 0; i < kBoardSize; ++i) {
    for (int j = 0; j < kBoardSize; ++j) {
      ss >> puzzles[i][j];
    }
  }
  solver.SetStartState(puzzles);
  solver.Run();
  int steps_count = solver.GetLength();
  string actions = solver.GetActions();
  EXPECT_EQ(steps_count, 22);
  EXPECT_EQ(actions, "RDLDRRULLDRUURDDLLURRD");
}