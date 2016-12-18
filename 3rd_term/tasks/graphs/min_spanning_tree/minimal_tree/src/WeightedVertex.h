/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#ifndef D_WEIGHTEDVERTEX_H
#define D_WEIGHTEDVERTEX_H

class WeightedVertex {
 public:
  int index_;
  unsigned long long int weight_;
  WeightedVertex(int index, unsigned long long int weight) noexcept;
  bool operator<(const WeightedVertex &second_vertex) const noexcept;
};

#endif //D_WEIGHTEDVERTEX_H
