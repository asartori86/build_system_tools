#include <iostream>
#include "strange_sum.hpp"
#include "strange_mult.hpp"

int main(int argc, char * argv[]) {

  std::vector<int> vecA, vecB;

  for (int i = 0; i < 8; ++i) {
    vecA.push_back(i*4 + 2);
    vecB.push_back(i*5 + 3);
  }

  std::cout << "strange_sum(vecA, vecB): " << strange_sum(vecA, vecB) << std::endl;
  std::cout << "strange_mult(vecA, vecB): " << strange_mult(vecA, vecB) << std::endl;
  
  // int sumA, sumB, multA;
  // double absA, absB;

  // sumA = sum_range(vecA, 0, 10);
  // sumB = sum_range(vecB, 0, 5);
  // multA = mult_range(vecA, 7, 10);
  // absA = abs(vecA);
  // absB = abs(vecB);
  
  // std::cout << "Sum of all elems of vecA: " << sumA << std::endl;
  // std::cout << "Sum of first 5 elems of vecB: " << sumB << std::endl;
  // std::cout << "abs of vecA: " << absA << std::endl;
  // std::cout << "abs of vecB: " << absB << std::endl;
  // std::cout << "Multiplication of last three elems of vecA: " << multA << std::endl;
  
  return 0;
}
