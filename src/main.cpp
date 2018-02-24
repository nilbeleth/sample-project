/**
* @file      main.cpp
* @copyright (c) 2018 by Matej Odalos <nilbeleth@valec.net>
* @license   MIT, see the @c LICENSE file for more details
* @brief     Simple Hello world!!! application.
*/
#include <iostream>
#include <cstdlib>
#include "version.h"


using namespace std;


/**
 * @brief Entry point of application.
 * @param[in] argc Number of command line arguments.
 * @param[in] argv Command line passed to application.
 * @return @c returns true if application finishes without any error,
 *         @c false otherwise/
 *
 * This application actually does nothing besides printing simple message.
 *
 */
int main(int argc, char const* argv[])
{
    cout << "Hello world! - " << Version::getBuildMachine() << endl;

    return EXIT_SUCCESS;
}
