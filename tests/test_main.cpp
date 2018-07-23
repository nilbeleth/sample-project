/**
 * @file      test_main.cpp
 * @copyright (c) 2018 by Matej Odalos <nilbeleth@valec.net>
 * @license   MIT, see the @c LICENSE file for more details
 * @brief     Simple Hello world!!! application.
 */
#include <catch2/catch.hpp>

#define CATCH_CONFIG_MAIN


namespace sample-project
{

    unsigned int Factorial( unsigned int number ) {
        return number <= 1 ? number : Factorial(number - 1)*number;
    }

namespace tests
{
    TEST_CASE( "Sem netusom co mam dat", "[funkcia]")
    {
        REQUIRE( Factorial(0) == 1 );
    }
}   // ned namespace tests
}   // end namespace sample-project
