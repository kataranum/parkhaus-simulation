#include <stdio.h>
#include <assert.h>
#include <test_utils.h>
#include <parse_num.h>

// test successful parsing
void test_parse_ulong(void) {
    char *test_inputs[] = {
        "123",
        "5",
        "0101",
        "0",
        "   456  ",
        "2147483648",
    };
    unsigned long expected_outputs[] = {
        123,
        5,
        101,
        0,
        456,
        2147483648,
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
    char *test_inputs[] = {
        "123",
        "5",
        "0101",
        "0",
        "   456  ",
    };
    unsigned int expected_outputs[] = {
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
        unsigned int output = 0;
        bool success = parse_uint(test_inputs[i], &output);

        assert(success);
        assert(output == expected_outputs[i]);
    }
}

// test graceful failure on invalid strings
void test_parse_invalid_uint(void) {
    char *test_inputs[] = {
        "asdf",
        "-5",
        "",
        "5a",
        "10.0",
    };

    const int AMOUNT_INPUTS = sizeof(test_inputs) / sizeof(test_inputs[0]);

    for (int i = 0; i < AMOUNT_INPUTS; i++) {
        unsigned int output = 37;
        bool success = parse_uint(test_inputs[i], &output);

        assert( ! success );
        assert(output == 37);
    }
}

// test graceful failure on values too large for uint
void test_parse_big_uint(void) {
    unsigned int output = 37;
    bool success = parse_uint("2147483648", &output);

    assert( ! success );
    assert(output == 37);
}

// test successful parsing
void test_parse_float(void) {
    char *test_inputs[] = {
        "1.0",
        "37",
        "0.5",
        "-2.3",
        "0.0",
        "   -12.34  ",
    };
    float expected_outputs[] = {
        1.0,
        37.0,
        0.5,
        -2.3,
        0.0,
        -12.34,
    };

    const int AMOUNT_INPUTS = sizeof(test_inputs) / sizeof(test_inputs[0]);
    const int AMOUNT_OUTPUTS = sizeof(expected_outputs) / sizeof(expected_outputs[0]);

    assert(AMOUNT_INPUTS == AMOUNT_OUTPUTS);

    for (int i = 0; i < AMOUNT_INPUTS; i++) {
        float output = 0;
        bool success = parse_ufloat(test_inputs[i], &output);

        assert(success);
        assert(cmp_float(output, expected_outputs[i]));
    }
}

// test graceful failure on invalid strings
void test_parse_invalid_float(void) {
    char *test_inputs[] = {
        "asdf",
        "0,1",
        "",
        "--3.1",
        "5a",
        "NaN",
        "inf",
    };

    const int AMOUNT_INPUTS = sizeof(test_inputs) / sizeof(test_inputs[0]);

    for (int i = 0; i < AMOUNT_INPUTS; i++) {
        float output = 2.0;
        bool success = parse_ufloat(test_inputs[i], &output);

        assert( ! success );
        assert(output == 2.0);
    }
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
