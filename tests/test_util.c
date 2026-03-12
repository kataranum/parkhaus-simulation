#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <util.h>

const long TEST_SEEDS[] = {
    42, 123, 987,
};
const int TEST_SEED_AMOUNT = sizeof(TEST_SEEDS) / sizeof(TEST_SEEDS[0]);

void test_frand(long seed) {
    #define NUM_TESTS 10000

    srand(seed);
}

int main(void) {
    for (int i = 0; i < TEST_SEED_AMOUNT; i++) {
        test_frand(TEST_SEEDS[i]);
    }

    printf("Alle Unit Tests sind erfolgreich durchgelaufen.\n");
    return 0;
}
