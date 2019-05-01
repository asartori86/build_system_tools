#include "min_vec.hpp"

void min_vec(std::vector<int> vec1, std::vector<int> vec2, std::vector<int>& min_vec) {

  int size = vec1.size();
  
  if (vec1.size() != vec2.size())
    throw std::length_error("The vectors are not of the same length");

  for (int i = 0; i < size; ++i)
    min_vec.push_back(min(vec1[i], vec2[i]));
}
