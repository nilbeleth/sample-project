/**
 * @file      main.cpp
 * @copyright (c) 2018 by Matej Odalos <nilbeleth@valec.net>
 * @license   MIT, see the @c LICENSE file for more details
 * @brief     Simple Hello world!!! application.
 */
#include <iostream>
#include <cstdlib>
#include "version.h"
#include "main.h"


using namespace std;


#ifndef UNIT_TESTS
int main(int argc, char const* argv[])
#else
int main_test(int argc, const char **argv)
#endif
{
  (void) argc;
  (void) argv;
  cout << "Hello world! - " << Version::getBuildMachine() << endl;

  return EXIT_SUCCESS;
}
