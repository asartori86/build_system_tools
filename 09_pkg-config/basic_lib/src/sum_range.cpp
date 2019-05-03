#include "sum_range.hpp"

int sum_range(std::vector<int>& vec, int min, int max) {

  int sum = 0;

  if (min < 0 || max > vec.size())
    throw std::out_of_range("min or max parameters are out of range");
  
  for (int i = min; i < max; ++i)
    sum += vec[i];
  
  return sum;
}
