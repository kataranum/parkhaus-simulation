/**
 * File: test_utils.h
 * Description: Utility functions used for unit tests; not included in actual
 * build
 */

#ifndef UTIL_TEST_H
#define UTIL_TEST_H

#include <stdbool.h>

/**
 * @brief Check for approximate float equality
 *
 * Calculates the difference between both values, if the difference is below a
 * predefined threshold consider the values equal.
 *
 * @param[in] a First value (order shouldn't matter)
 * @param[in] b Second value (oder shouldn't matter)
 * @return bool Return `true` if a and b are very close to each other
 */
bool cmp_float(float a, float b);

/**
 * @breif Check for approximate float equality with given epsilon value
 *
 * Calculates the difference between both values, if the difference is less than
 * `epsilon` consider the values equal.
 *
 * @param[in] a First value (order shouldn't matter)
 * @param[in] b Second value (oder shouldn't matter)
 * @param[in] epsilon Given epsilon value for equality threshold
 * @return bool Return `true` if difference of a and b is smaller than epsilon
 */
bool cmp_float_epsilon(float a, float b, float epsilon);

#endif
