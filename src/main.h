/**
 * @file      main.cpp
 * @copyright (c) 2018 by Matej Odalos <nilbeleth@valec.net>
 * @license   MIT, see the @c LICENSE file for more details
 * @brief     Simple Hello world!!! application.
 */
#ifndef SAMPLE_PROJECT_MAIN_H
#define SAMPLE_PROJECT_MAIN_H


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
#ifndef UNIT_TESTS
int main(int argc, char const* argv[]);
#else
int main_test(int argc, char const* argv[]);
#endif

#endif //SAMPLE_PROJECT_MAIN_H
