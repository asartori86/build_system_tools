#include <iostream>

#include "constants.h"
#include "mathematics.h"
#include "physics.h"

int main(int argc, char* argv[]) {
  std::cout << "area of a circle " << math::circle::area(1.0) << std::endl;

  std::cout << "perimeter of a circle " << math::circle::perimeter(1.0)
            << std::endl;

  std::cout << "Coulomb's force "
            << physics::electromag::coulomb_force(1. * ec, 1. * ec, 1e-10)
            << std::endl;

  return 0;
}
