#include "../inc/user_input.h"

/*
```PSEUDOCODE
DO
    input = READ_INPUT
WHILE !is_valid(input);

RETURN input AS unsigned int;
```
*/
unsigned int input_valid_uint(void) {
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
float percentage;
input_valid_float(&percentage);
assert_float_range(percentage, 0.0, 100.0);
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
