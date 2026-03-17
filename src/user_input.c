#include <user_input.h>
#include <parse_num.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define INPUT_BUFFER_SIZE 256

/**
 * @brief Read a line of text from stdin and remove the trailing newline character
 * @param text Buffer to store the input text
 * @param size Size of the buffer
 * @return true for valid input
 * @return false for failed input
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

/**
 * @brief Prompt user for a valid unsigned int input
 *
 * @param prompt_str[in] Prompt to print
 * @return unsigned int value entered by the user
 */
unsigned int input_valid_uint(const char *prompt_str)
{
    while (true)
    {
        printf("%s", prompt_str);

        char input[INPUT_BUFFER_SIZE];
        if ( ! read_user_text(input, sizeof(input)) )
        {
            printf("Invalid input\n");
            continue;
        }

        unsigned int value = 0;
        if ( ! parse_uint(input, &value) )
        {
            printf("invalid uint");
            continue;
        }
        
        return value;
    }

}

/**
 * @brief Prompt user for a valid seed input (unsigned long) or use current time if empty
 *
 * @param prompt_str[in] Prompt to print
 * @return unsigned long seed value
 */
unsigned long input_valid_seed(const char *prompt_str)
{
    while (true)
    {
        printf("%s", prompt_str);

        char input[INPUT_BUFFER_SIZE];
        if ( ! read_user_text(input, sizeof(input)) )
        {
            printf("Invalid input\n");
            continue;
        }

        if (strlen(input) == 0)
        {
            return (unsigned int)time(NULL);
        }

        unsigned long value = 0;
        if ( ! parse_ulong(input, &value) )
        {
            printf("invalid ulong");
            continue;
        }
        
        return value;
    }
}

/**
 * @brief Prompt user for a valid percentage input (0 - 100)
 *
 * @param prompt_str[in] Prompt to print
 * @return float value entered by the user
 */
float input_valid_percentage(const char *prompt_str)
{
    while (true)
    {
        printf("%s", prompt_str);

        char input[INPUT_BUFFER_SIZE];
        if ( ! read_user_text(input, sizeof(input)) )
        {
            printf("Invalid input\n");
            continue;
        }

        float value = 0.0;
        if ( ! parse_float(input, &value) )
        {
            printf("invalid float\n");
            continue;
        }
        
        if (value < 0.0 || value > 100.0)
        {
            printf("value is outside allowed range (0%% - 100%%)\n");
            continue;
        }
        
        return value;
    }
}

InputParams get_user_input(void)
{
    InputParams params;

    params.park_num_spaces = input_valid_uint("Please input number of parking spaces: ");   
    params.park_max_time = input_valid_uint("Please input maximum number of timesteps that cars will park for: "); 

    float percentage = input_valid_percentage("Please enter a percentage chance of cars arriving on a new timestep: ");
    params.park_chance_arrive = percentage / 100.0;

    params.total_time_steps = input_valid_uint("Please input how many timesteps should be simulated: ");
    params.rng_seed = input_valid_seed("Enter seed (leave empty for random seed): ");

    return params;
}
