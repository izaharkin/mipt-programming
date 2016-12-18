#include "avg.h"

namespace avg
{

int avg( std::vector<int> data )
{
  int sum = 0;
  for( unsigned int i = data.size(); -1 < i; i-- )
    sum += data[i];
  return sum / data.size();
}

}
