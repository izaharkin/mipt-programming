/*
 * @author Ilya Zakharkin
 * @since 27.10.16
 */

#include "Edge.h"

Edge::Edge()
    : from_(-1), to_(-1), weight_(kInf) {}

Edge::Edge(int from, int to, unsigned long long weight)
    : from_(from), to_(to), weight_(weight) {}

bool Edge::operator<(const Edge &second_edge) const  {
  return this->weight_ < second_edge.weight_;
}