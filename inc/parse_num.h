/**
 * File: parse_num.h
 * Description: Functions to parse strings to certain values
 */

#ifndef PARSE_NUM_H
#define PARSE_NUM_H

#include <stdbool.h>

/**
 * @brief Parse the given string as uint
 * 
 * Return true on success, return false on parsing error (p_val remains
 * untouched in that case)
 *
 * @param[in]  str    Given string
 * @param[out] p_val Parsed value
 * @return           Success
 */
bool parse_uint(const char *str, unsigned int *p_val);

/**
 * @brief Parse the given string as ulong
 * 
 * Return true on success, return false on parsing error (p_val remains
 * untouched in that case)
 *
 * @param[in]  str   Given string
 * @param[out] p_val Parsed value
 * @return           Success
 */
bool parse_ulong(const char *str, unsigned long *p_val);

/**
 * @brief Parse the given string as a float
 * 
 * Return true on success, return false on parsing error (p_val remains
 * untouched in that case)
 *
 * @param[in]  str   Given string
 * @param[out] p_val Parsed value
 * @return           Success
 */
bool parse_float(const char *str, float *p_val);

#endif
