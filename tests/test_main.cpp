/**
 * @file      test_main.cpp
 * @copyright (c) 2018 by Matej Odalos <nilbeleth@valec.net>
 * @license   MIT, see the @c LICENSE file for more details
 * @brief     Simple Hello world!!! application.
 */
#include <catch.hpp>

#define CATCH_CONFIG_MAIN


namespace sample-project
{
namespace tests
{
    TEST_CASE( "Sem netusom co mam dat", "[funkcia]")
    {
        REQUIRE( 1 == 2 );
    }
}   // ned namespace tests
}   // end namespace sample-project
