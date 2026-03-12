#include <parse_num.h>

bool parse_uint(const char *str, unsigned int *p_val) {

}

bool parse_ulong(const char *str, unsigned long *p_val) {
    char *end;
    long value = strtol(str, &end, 10);

    if (str == end || value < 0) {
        return false;
    }

    *p_val = (unsigned long) value;
    return true;
}

bool parse_float(const char *str, float *p_val) {
    
}
