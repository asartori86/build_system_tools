#include "physics.h"
#include "constants.h"
#include <stdexcept>

namespace physics {

  namespace electromag {

    double coulomb_force(const double q1, const double q2, const double r) {
      if (r > 0)
	return ke * q1 * q2 / (r * r);
      throw std::runtime_error{"Distance cannot be negative or null"};
    }

  }  // namespace electromag

}  // namespace physics
