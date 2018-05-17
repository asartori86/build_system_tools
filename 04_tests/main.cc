#include <iostream>
#include <stdexcept>
#include <fstream>

#include "constants.h"
#include "mathematics.h"
#include "physics.h"

int main(int argc, char *argv[]){
  try{
    if (argc <=1 )
      throw std::runtime_error{"\n\nI need exactly one argument, which is the input file.\n\n"};
    
    std::ifstream input_file{argv[1]};

    double radius;
    input_file >> radius;

    double distance;
    input_file >> distance;
  
    std::cout << "area of a circle " << math::circle::area(radius) << std::endl;

    std::cout << "perimeter of a circle " << math::circle::perimeter(radius)
	      << std::endl;

    std::cout << "Coulomb's force "
	      << physics::electromag::coulomb_force(1. * ec, 1. * ec, distance)
	      << std::endl;

    return 0;
  }
  catch (std::exception& e){
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
