#ifndef USER_INPUT_H
#define USER_INPUT_H

/**
 * @brief All values that come from user input
 */
typedef struct {
    /** Number of spaces in the parking lot */
    unsigned int park_num_spaces;
    /** Maximum time a car may park for */
    unsigned int park_max_time;
    /** Chance that new car will arrive each timestep (valid range 0 - 1) */
    float park_chance_arrive;

    /** Number of timesteps the simulation will run for */
    unsigned int total_time_steps;
    /** Seed for rng functions */
    unsigned long rng_seed;
} InputParams;

#endif
