#include <parse_num.h>

bool parse_uint(const char *str, unsigned int *p_val)
{
    unsigned long tmp = 0;

    bool success = parse_ulong(str, &tmp);

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

    if (str == end || value < 0)
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

    if (str == end)
    {
        return false;
    }

    *p_val = value;
    return true;
}
