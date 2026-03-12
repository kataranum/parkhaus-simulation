#include <stdio.h>
#include <assert.h>
#include <parse_num.h>

// test successful parsing
void test_parse_ulong(void) {
    char *test_inputs[] = {
        "123",
        "5",
        "0101",
        "0",
        "   456  ",
    };
    unsigned long expected_outputs[] = {
        123,
        5,
        101,
        0,
        456,
    };

    const int AMOUNT_INPUTS = sizeof(test_inputs) / sizeof(test_inputs[0]);
    const int AMOUNT_OUTPUTS = sizeof(expected_outputs) / sizeof(expected_outputs[0]);

    assert(AMOUNT_INPUTS == AMOUNT_OUTPUTS);

    for (int i = 0; i < AMOUNT_INPUTS; i++) {
        unsigned long output = 0;
        bool success = parse_ulong(test_inputs[i], &output);

        assert(success);
        assert(output == expected_outputs[i]);
    }
}

// test graceful failure on invalid strings
void test_parse_invalid_ulong(void) {
    char *test_inputs[] = {
        "asdf",
        "-5",
        "",
        "5a",
        "10.0",
    };

    const int AMOUNT_INPUTS = sizeof(test_inputs) / sizeof(test_inputs[0]);

    for (int i = 0; i < AMOUNT_INPUTS; i++) {
        unsigned long output = 37;
        bool success = parse_ulong(test_inputs[i], &output);

        assert( ! success );
        assert(output == 37);
    }
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
