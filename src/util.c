#include <../inc/util.h>
#define RAND_MAX 2147483647
/*
```PSEUDOCODE
RETURN (float)rand() / (float)RAND_MAX;
```
*/
float frand() {
    return (float)rand() / (float)RAND_MAX;
}
