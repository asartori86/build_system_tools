#include "abs.hpp"

int abs(std::vector<int>& vec) {

  int sum = 0;
  double sqrt;

  sum = dot(vec, vec);
  sqrt = std::sqrt(sum);
  
  return sqrt;
}
