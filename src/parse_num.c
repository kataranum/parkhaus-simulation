#include <parse_num.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool parse_uint(const char *str, unsigned int *p_val)
{
    unsigned long tmp = 0;

    bool success = parse_ulong(str, &tmp);

    // ensure parse_ulong succeeded and value fits into int
    if (!success || tmp > INT_MAX)
    {
        return false;
    }

    *p_val = (unsigned int) tmp;
    return true;
}

bool parse_ulong(const char *str, unsigned long *p_val)
{
    char *end;
    long value = strtol(str, &end, 10);

    // ensure strtol succeded and value is positive
    if (str == end || value < 0)
    {
        return false;
    }

    // ensure whole string was parsed
    int parsed_len = (int) (end - str);
    if (strlen(str) != parsed_len)
    {
        return false;
    }

    *p_val = (unsigned long) value;
    return true;
}

bool parse_float(const char *str, float *p_val)
{
    char *end;
    float value = strtof(str, &end);

    // ensure strtof succeeded
    if (str == end)
    {
        return false;
    }

    // ensure whole string was parsed
    int parsed_len = (int) (end - str);
    if (strlen(str) != parsed_len)
    {
        return false;
    }

    // ensure float value is a number (not NaN or INF)
    if (!isfinite(value))
    {
        return false;
    }

    *p_val = value;
    return true;
}
