#include "physics.h"
#include "constants.h"

namespace physics {

  namespace electromag {

    double coulomb_force(const double q1, const double q2, const double r) {
      return ke * q1 * q2 / (r * r);
    }

  }  // namespace electromag

}  // namespace physics
