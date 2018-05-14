#ifndef __physics_h__
#define __physics_h__

namespace physics {

  namespace electromag {

    double coulomb_force(const double q1,
                         const double q2,
                         const double distance);

  }  // end namespace electromag

}  // end namespace physics

#endif
