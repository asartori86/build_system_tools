#include "doctest.h"

#include "mathematics.h"
#include "constants.h"
#include <stdexcept>
using namespace doctest;
TEST_CASE("circle area value") {
  REQUIRE(Approx(0.) == math::circle::area(0.));
  REQUIRE(Approx(pi) == math::circle::area(1.));
  REQUIRE(Approx(pi*4.) == math::circle::area(2.));
}


TEST_CASE("circle area THROWS"){
  REQUIRE_NOTHROW(math::circle::area(10.));
  REQUIRE_THROWS(math::circle::area(-1.));
  REQUIRE_THROWS_AS(math::circle::area(-2.), std::runtime_error);
}

TEST_CASE("circle perimeter"){
  CHECK(Approx(0.) == math::circle::perimeter(0.));
  CHECK(Approx(pi*2.) == math::circle::perimeter(1.0));
  CHECK(Approx(pi*6.0) == math::circle::perimeter(3.0));
}


TEST_CASE("circle perimeter THROWS"){
  REQUIRE_NOTHROW(math::circle::perimeter(10.));
  REQUIRE_THROWS(math::circle::perimeter(-1.));
  REQUIRE_THROWS_AS(math::circle::perimeter(-2.), std::runtime_error);
}

