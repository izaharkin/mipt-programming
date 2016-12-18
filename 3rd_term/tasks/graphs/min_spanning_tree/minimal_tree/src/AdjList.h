/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_ADJLIST_H
#define D_ADJLIST_H

#include "WeightedVertex.h"
#include "Matrix.h"

class AdjList {
 public:
  AdjList() ;
  ~AdjList() ;
  AdjList(int size) ;
  AdjList(const Matrix<WeightedVertex> &matrix) ;
  int GetSize() const ;
  vector<WeightedVertex> operator[](int vertex) const ;
  vector<WeightedVertex> &operator[](int vertex) ;
 private:
  Matrix<WeightedVertex> adj_list_;
};

#endif //D_ADJLIST_H
