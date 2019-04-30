#include "strange_mult.hpp"

double strange_mult(std::vector<int> vec1, std::vector<int> vec2) {

  double result;
  int size = vec1.size();
  int multA, multB, sum;
  
  if (vec1.size() != vec2.size())
    throw std::length_error("The vectors are not of the same length");

  multA = mult_range(vec1, 0, size);
  multB = mult_range(vec2, 0, size);

  sum = multA + multB;
  result = std::sqrt(sum);
  return result;
}
