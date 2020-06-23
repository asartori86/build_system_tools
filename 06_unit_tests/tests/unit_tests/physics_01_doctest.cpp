#include "doctest.h"
#include "physics.h"
#include "constants.h"
#include <stdexcept>

using namespace doctest;

TEST_CASE("coulomb force_01") {
  REQUIRE(Approx(ke) == physics::electromag::coulomb_force(1.,1.,1.));
  REQUIRE(Approx(ke*1e20) == physics::electromag::coulomb_force(1.,1.,1e-10));
}

TEST_CASE("coulomb force_02") {
  REQUIRE_NOTHROW( physics::electromag::coulomb_force(1.,1.,1.));
  REQUIRE_THROWS_AS(physics::electromag::coulomb_force(1.,1., -1e-10), std::runtime_error);
}
