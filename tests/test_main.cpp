/**
 * @file      test_main.cpp
 * @copyright (c) 2018 by Matej Odalos <nilbeleth@valec.net>
 * @license   MIT, see the @c LICENSE file for more details
 * @brief     A unit test for src/main.cpp
 */
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <main.h>

TEST_CASE( "Main test function", "[triple-file]" ) {
  const char *cmd_line[] = {"unittests", "a"};
  REQUIRE( 0 == main_test(1, cmd_line) );
}
