#include <../inc/util.h>
#define RAND_MAX 2147483647

float frand()
{
    return (float)rand() / (float)RAND_MAX;
}
