/*****************************************************************************\
 * Project:   sample-project
 * Copyright: (c) 2018 by Matej Odalos <nilbeleth@valec.net>
 * License:   MIT, see the LICENSE file for more details
 *
 * Simple Hello world!!! application.
 *
\*****************************************************************************/
#include <iostream>
#include <cstdlib>
#include "version.h"
#include "main.h"

using namespace std;


int main(int argc, char const* argv[])
{
  (void) argc;
  (void) argv;
  cout << "Hello world!" << endl;

  return EXIT_SUCCESS;
}
