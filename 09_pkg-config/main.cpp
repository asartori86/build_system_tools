#include <iostream>
#include "strange_sum.hpp"
#include "strange_mult.hpp"
#include "min_vec.hpp"
#include "max_vec.hpp"

int main(int argc, char * argv[]) {

  std::vector<int> vecA, vecB;

  for (int i = 0; i < 8; ++i) {
    vecA.push_back(i*4 + 2);
    vecB.push_back(i*5 + 3);
  }
  
  std::cout << "strange_sum(vecA, vecB): " << strange_sum(vecA, vecB) << std::endl;
  std::cout << "strange_mult(vecA, vecB): " << strange_mult(vecA, vecB) << std::endl;
  
  std::vector<int> min_vecAB, max_vecAB;
  min_vec(vecA, vecB, min_vecAB);
  max_vec(vecA, vecB, max_vecAB);
  
  for (int i = 0; i < vecA.size(); ++i)
    std::cout << "min_vec[" << i << "]: " << min_vecAB[i] << std::endl;
							     
  for (int i = 0; i < vecA.size(); ++i)
    std::cout << "max_vec[" << i << "]: " << max_vecAB[i] << std::endl; 

							     
  return 0;
}
