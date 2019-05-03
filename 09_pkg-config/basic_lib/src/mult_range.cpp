#include "mult_range.hpp"

int mult_range(std::vector<int>& vec, int min, int max) {

  int mult = 1;

  if (min < 0 || max > vec.size())
    throw std::out_of_range("min or max parameters are out of range");
  
  for (int i = min; i < max; ++i)
    mult *= vec[i];
  
  return mult;
}
