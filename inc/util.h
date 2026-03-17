/**
 * File: util.h
 * Description: Helpful functions that aren't specific to a feature of the
 *              program
 */

#ifndef UTIL_H
#define UTIL_H

/**
 * @brief Return a random float between 0.0 and 1.0
 * 
 * Uses `rand()` internally so uses the seed set by `srand()`
 *
 * @return Random float between 0 and 1
 */
float frand();

#endif
