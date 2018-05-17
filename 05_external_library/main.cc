#include <fstream>
#include <iostream>

#include "constants.h"
#include "mathematics.h"
#include "physics.h"

#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

int main(int argc, char* argv[]) {
  try {
    double radius;
    double distance;
    bpo::options_description desc("Allowed options");
    desc.add_options()
      ("radius", bpo::value<double>(&radius)->default_value(0.0),
       "radius of the circle.")
      ("distance", bpo::value<double>(&distance)->default_value(1.0),
       "distance between the charges.")
      ("help,h", "print this message.");

    bpo::variables_map vm;
    try {
      bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
      bpo::notify(vm);
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
      std::cerr << desc << std::endl;
      return 1;
    }

    if (vm.count("help")) {
      std::cout << desc << "\n";
      return 1;
    }

    std::cout << "area of a circle " << math::circle::area(radius) << std::endl;

    std::cout << "perimeter of a circle " << math::circle::perimeter(radius)
              << std::endl;

    std::cout << "Coulomb's force "
              << physics::electromag::coulomb_force(1. * ec, 1. * ec, distance)
              << std::endl;

    return 0;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
    return 1;
  }
}
