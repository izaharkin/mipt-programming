/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "WeightedVertex.h"

WeightedVertex::WeightedVertex(int index, unsigned long long int weight) noexcept
    : index_(index), weight_(weight) {}

bool WeightedVertex::operator<(const WeightedVertex &second_vertex) const noexcept {
  return this->weight_ < second_vertex.weight_;
}