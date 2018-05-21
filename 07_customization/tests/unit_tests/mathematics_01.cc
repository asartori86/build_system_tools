#include <gtest/gtest.h>
#include "mathematics.h"
#include "constants.h"

TEST(circle, area_01) {
  EXPECT_DOUBLE_EQ(0., math::circle::area(0.));
  EXPECT_DOUBLE_EQ(pi, math::circle::area(1.0));
  EXPECT_DOUBLE_EQ(pi*4.0, math::circle::area(2.0));
}

TEST(circle, area_02) {
  EXPECT_NO_THROW(math::circle::area(10.0));
  EXPECT_ANY_THROW(math::circle::area(-1.0));
  EXPECT_THROW(math::circle::area(-1.0), std::runtime_error);
}


TEST(circle, perimeter_01) {
  EXPECT_DOUBLE_EQ(0., math::circle::perimeter(0.));
  EXPECT_DOUBLE_EQ(pi*2., math::circle::perimeter(1.0));
  EXPECT_DOUBLE_EQ(pi*6.0, math::circle::perimeter(3.0));
}

TEST(circle, perimeter_02) {
  EXPECT_NO_THROW(math::circle::perimeter(10.0));
  EXPECT_ANY_THROW(math::circle::perimeter(-1.0));
  EXPECT_THROW(math::circle::perimeter(-1.0), std::runtime_error);
}
