#include <gtest/gtest.h>
#include "physics.h"
#include "constants.h"

TEST(coulomb, force_01) {
  EXPECT_DOUBLE_EQ(ke, physics::electromag::coulomb_force(1.,1.,1.));
  EXPECT_DOUBLE_EQ(ke*1e20, physics::electromag::coulomb_force(1.,1.,1e-10));
}

TEST(coulomb, force_02) {
  EXPECT_NO_THROW( physics::electromag::coulomb_force(1.,1.,1.));
  EXPECT_THROW(physics::electromag::coulomb_force(1.,1., -1e-10), std::runtime_error);
}
