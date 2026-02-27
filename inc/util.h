#ifndef UTIL_H
#define UTIL_H

/**
 * @brief Return a random float between 0.0 (inclusive) and 1.0 (exclusive)
 * 
 * Uses `rand()` internally so uses the seed set by `srand()`
 *
 * @return float Random float between 0 and 1
 */
float frand();

#endif
