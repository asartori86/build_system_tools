#include "mathematics.h"
#include "constants.h"
#include <stdexcept>

namespace math {

  namespace circle {

    double area(const double r) {
      if (r < 0)
	throw std::runtime_error{"Radius must be positive"};
      return pi * r * r;
    }

    double perimeter(const double r) {
      if (r < 0)
	throw std::runtime_error{"Radius must be positive"};
      return 2. * pi * r;
    }

  }  // namespace circle

}  // namespace math
