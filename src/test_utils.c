#include <test_utils.h>
#include <math.h>

bool cmp_float(float a, float b) {
    const float EPSILON = 0.0001;
    return cmp_float_epsilon(a, b, EPSILON);
}

bool cmp_float_epsilon(float a, float b, float epsilon) {
    float difference = fabs(a - b);
    return difference < epsilon;
}
