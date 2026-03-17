#include <util.h>
#include <stdlib.h>

/*
```PSEUDOCODE
RETURN (float)rand() / (float)RAND_MAX;
```
*/
float frand() {
    return (float)rand() / (float)RAND_MAX;
}
