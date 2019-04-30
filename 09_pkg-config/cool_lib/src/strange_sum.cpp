#include "strange_sum.hpp"

double strange_sum(std::vector<int> vec1, std::vector<int> vec2) {

  double result;
  int size = vec1.size();
  int sumA, sumB, sum;
  
  if (vec1.size() != vec2.size())
    throw std::length_error("The vectors are not of the same length");

  sumA = sum_range(vec1, 0, size);
  sumB = sum_range(vec2, 0, size);

  sum = sumA + sumB;
  result = std::sqrt(sum);
  return result;
}
