#include "dot.hpp"

int dot(std::vector<int>& vec1, std::vector<int>& vec2) {

  int sum = 0;
  int size = vec1.size();

  if (vec1.size() != vec2.size())
    throw std::length_error("The vectors are not of the same length");
  
  for (int i = 0; i < size; ++i)
    sum += vec1[i] * vec2[i];
  
  return sum;
}
