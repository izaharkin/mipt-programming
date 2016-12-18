/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_DSU_H
#define D_DSU_H

#include <vector>

using std::vector;

class DSU {
 public:
  vector<int> parent_;
  DSU() ;
  ~DSU() ;
  DSU(int size) ;
  int Get(int elem) ;
  void Unite(int first, int second) ;
 private:
  vector<int> rank;
};

#endif //D_DSU_H
