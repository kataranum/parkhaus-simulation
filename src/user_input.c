#include "../inc/user_input.h"

/*
```PSEUDOCODE
LOOP:
    input = READ_INPUT

    IF is_parsable(input):
        RETURN input AS unsigned int;
    END IF

    PRINT "invalid uint"
END LOOP
```
*/
unsigned int input_valid_uint(void) {
    // TODO
}

/*
```PSEUDOCODE
LOOP:
    input = READ_INPUT

    IF is_parsable(input):
        RETURN input AS unsigned long;
    END IF

    PRINT "invalid ulong"
END LOOP
```
*/
unsigned int input_valid_long(void) {
    // TODO
}

/*
```PSEUDOCODE
LOOP:
    input = READ_INPUT

    IF !is_parsable(input):
        PRINT "invalid float"
        CONTINUE;
    END IF

    value = input AS float;

    IF value < 0.0 OR value > 100.0:
        PRINT "value is outside allowed range (0% - 100%)"
        CONTINUE;
    END IF

    RETURN value;
END LOOP
```
*/
float input_valid_percentage(void) {
    // TODO
}

/*
```PSEUDOCODE
InputParams params;

PRINT "Please input number of parking spaces"
params.park_num_spaces = input_valid_uint();

PRINT "Please input maximum number of timesteps that cars will park for"
params.park_max_time = input_valid_uint();

PRINT "Please enter a percentage chance of cars arriving on a new timestep"
float percentage = input_valid_percentage();
params.park_chance_arrive = percentage / 100.0;

PRINT "Please input how many timesteps should be simulated"
params.total_time_steps = input_valid_uint();

PRINT "Enter seed (leave empty for random seed)"
input_valid_ulong(&params.rng_seed);

RETURN params
```
*/
InputParams get_user_input(void) {
    // TODO
}
