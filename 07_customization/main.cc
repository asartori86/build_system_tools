#include <iostream>
#include <stdexcept>
#include <fstream>

// put as first
#include "my_project_config.h"

#include "constants.h"

#ifdef BUILD_MATHEMATICS
#include "mathematics.h"
#endif

#ifdef BUILD_PHYSICS
#include "physics.h"
#endif


int main(int argc, char *argv[]){
  try{
    if (argc <=1 )
      throw std::runtime_error{"\n\nI need exactly one argument, which is the input file.\n\n"};
    
    std::ifstream input_file{argv[1]};

    double radius;
    input_file >> radius;

    double distance;
    input_file >> distance;

#ifdef BUILD_MATHEMATICS    
    std::cout << "area of a circle " << math::circle::area(radius) << std::endl;

    std::cout << "perimeter of a circle " << math::circle::perimeter(radius)
	      << std::endl;
#endif

#ifdef BUILD_PHYSICS
    
    std::cout << "Coulomb's force "
	      << physics::electromag::coulomb_force(1. * ec, 1. * ec, distance)
	      << std::endl;
#endif
    return 0;
  }
  catch (std::exception& e){
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
