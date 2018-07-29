/**
 * @file      test_version.cpp
 * @copyright (c) 2018 by Matej Odalos <nilbeleth@valec.net>
 * @license   MIT, see the @c LICENSE file for more details
 * @brief     A unit test for @ref ../src/version.cpp
 */
#include <catch2/catch.hpp>
#include <version.h>
#include <vector>


SCENARIO( "vectors can be sized and resized", "[vector]" ) {

  // NOTE: This whole section is just a nice example of behavior driven testing.

  GIVEN( "A vector with some items" ) {
    std::vector<int> v( 5 );

    REQUIRE( v.size() == 5 );
    REQUIRE( v.capacity() >= 5 );

    WHEN( "the size is increased" ) {
      v.resize( 10 );

      THEN( "the size and capacity change" ) {
        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10 );
      }
    }
    WHEN( "the size is reduced" ) {
      v.resize( 0 );

      THEN( "the size changes but not capacity" ) {
        REQUIRE( v.size() == 0 );
        REQUIRE( v.capacity() >= 5 );
      }
    }
    WHEN( "more capacity is reserved" ) {
      v.reserve( 10 );

      THEN( "the capacity changes but not the size" ) {
        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 10 );
      }
    }
    WHEN( "less capacity is reserved" ) {
      v.reserve( 0 );

      THEN( "neither size nor capacity are changed" ) {
        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );
      }
    }
  }
}

TEST_CASE( "Check the version number constants", "[version][accessors]" ) {

  SECTION("Verify the version number getters") {
    REQUIRE(0==Version::getMajor());
    REQUIRE(0==Version::getMinor());
    REQUIRE(1==Version::getPatch());

    REQUIRE(1==Version::getVersionNumber());
  }
}

TEST_CASE( "Check the build information", "[version][untestable]") {

  // There are several accessors that are not really testable. They functionality is configured by CMake and depends
  // strictly on when and how is the project built. There is no reason to create extravagant test just to verify such
  // wonky functionality. These tests are here mostly to obtain coverage.
  // TODO: consider using Catch2 matchers

  SECTION("Verify Version::getBuildTime()") {
    CAPTURE(Version::getBuildTime())
    REQUIRE(true);
  }

  SECTION("Verify Version::getBuildMachine()") {
    CAPTURE(Version::getBuildMachine())
    REQUIRE(true);
  }

  SECTION("Verify Version::getVersionShort()") {
    CAPTURE(Version::getVersionShort())
    REQUIRE(true);
  }

  SECTION("Verify Version::getVersionLong()") {
    CAPTURE(Version::getVersionLong())
    REQUIRE(true);
  }
}
