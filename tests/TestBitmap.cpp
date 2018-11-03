// Let catch.hpp provide main():
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// incorrect implementation
// unsigned int Factorial(unsigned int number) {
//   return number <= 1 ? number : Factorial(number - 1) * number;
// }

// correct implementation
unsigned int Factorial( unsigned int number ) {
  return number > 1 ? Factorial(number-1)*number : 1;
}

TEST_CASE("Factorials are computed", "[factorial, math]") {
  REQUIRE(Factorial(0) == 1);
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
  REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Factorials are computed again", "[factorial, example, TDD]") {
  REQUIRE(Factorial(4) == 24);
}
