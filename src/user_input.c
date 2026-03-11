#include <stdio.h>
#include <string.h>
#include "../inc/user_input.h"
#include <stdbool.h>

#define INPUT_BUFFER_SIZE 256

/**
 * @brief Read a line of text from stdin and remove the trailing newline character
 * @param text Buffer to store the input text
 * @param size Size of the buffer
 * @return 0 on success, 1 on failure
 */

bool read_user_text(char *text, size_t size)
{
    if (fgets(text, size, stdin) == NULL)
    {
        return false;
    }

    text[strcspn(text, "\n")] = '\0';
    return true;
}

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
unsigned int input_valid_uint(void)
{
    while (1)
    {
        char input[INPUT_BUFFER_SIZE];
        read_user_text(input, sizeof(input));

        //TODO: implement is_parsable (for each function (float or int))
        if (is_parsable_uint(input))
        {
            return (unsigned int)input;
        }
        
        printf("invalid uint");
        break;
    }

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
float input_valid_percentage(void)
{
    while (1)
    {
        char input[INPUT_BUFFER_SIZE];
        read_user_text(input, sizeof(input));

        //TODO: implement is_parsable_float
        if (is_parsable_float(input))
        {
            float value = (float)atof(input);
            if (value < 0.0 || value > 100.0)
            {
                printf("value is outside allowed range (0\% - 100\%)\n");
                continue;
            }
            return value;
        }
        printf("invalid float\n");
    }
}

/*
```PSEUDOCODE
LOOP:
    input = READ_INPUT

    IF is_empty(input):
        RETURN time(NULL);
    END IF

    IF is_parsable(input):
        RETURN input AS unsigned long;
    END IF

    PRINT "invalid ulong"
END LOOP
```
*/
unsigned int input_valid_seed(void)
{
    while (1)
    {    
        char input[INPUT_BUFFER_SIZE];
        read_user_text(input, sizeof(input));

        if (strlen(input) == 0)
        {
            return (unsigned int)time(NULL);
        }

        if (is_parsable_uint(input))
        {
            return (unsigned int)input;
        }

        printf("invalid ulong");
    }
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
params.rng_seed = input_valid_seed();

RETURN params
```
*/
InputParams get_user_input(void)
{
    InputParams params;

    printf("Please input number of parking spaces: ");
    params.park_num_spaces = input_valid_uint();   

    printf("Please input maximum number of timesteps that cars will park for: ");
    params.park_max_time = input_valid_uint(); 

    printf("Please enter a percentage chance of cars arriving on a new timestep: ");
    float percentage = input_valid_percentage();
    params.park_chance_arrive = percentage / 100.0;

    printf("Please input how many timesteps should be simulated: ");
    params.total_time_steps = input_valid_uint();

    printf("Enter seed (leave empty for random seed): ");
    params.rng_seed = input_valid_seed();

    return params;
}
