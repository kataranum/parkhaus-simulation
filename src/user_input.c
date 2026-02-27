#include "../inc/user_input.h"

/*
```PSEUDOCODE
InputParams params;

PRINT "Please input number of parking spaces"
input_valid_uint(&params.park_num_spaces);

PRINT "Please input maximum number of timesteps that cars will park for"
input_valid_uint(&params.park_max_time);

PRINT "Please enter a percentage chance of cars arriving on a new timestep"
float percentage;
input_valid_float(&percentage);
assert_float_range(percentage, 0.0, 100.0);
params.park_chance_arrive = percentage / 100.0;

PRINT "Please input how many timesteps should be simulated"
input_valid_uint(&params.total_time_steps);

PRINT "Enter seed (leave empty for random seed)"
input_valid_ulong(&params.rng_seed);

RETURN params
```
*/
InputParams get_user_input(void) {
    // TODO
}
