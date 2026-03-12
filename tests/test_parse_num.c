#include <stdio.h>
#include <assert.h>
#include <parse_num.h>

// test successful parsing
void test_parse_ulong(void) {
    assert(false);
}

// test graceful failure on invalid strings
void test_parse_invalid_ulong(void) {
    assert(false);
}

// test successful parsing
void test_parse_uint(void) {
    assert(false);
}

// test graceful failure on invalid strings
void test_parse_invalid_uint(void) {
    assert(false);
}

// test graceful failure on values too large for uint
void test_parse_big_uint(void) {
    assert(false);
}

// test successful parsing
void test_parse_float(void) {
    assert(false);
}

// test graceful failure on invalid strings
void test_parse_invalid_float(void) {
    assert(false);
}

int main(void) {
    test_parse_ulong();
    test_parse_invalid_ulong();
    test_parse_uint();
    test_parse_invalid_uint();
    test_parse_big_uint();
    test_parse_float();
    test_parse_invalid_float();

    printf("Alle Unit-Tests sind erfolgreich durchgelaufen.\n");
    return 0;
}
