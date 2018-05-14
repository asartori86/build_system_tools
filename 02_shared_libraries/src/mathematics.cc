#include "mathematics.h"
#include "constants.h"

namespace math {

  namespace circle {

    double area(const double r) { return pi * r * r; }

    double perimeter(const double r) { return 2. * pi * r; }

  }  // namespace circle

}  // namespace math
