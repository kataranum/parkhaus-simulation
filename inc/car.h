#ifdef SIMULATION_H
#define SIMULATION_H
/**
 * @brief This struct is a definition of a car, which contains the id of the car, the time of arrival at the parking lot, the time of arrival at the queue and the duration of parking.
 */
typedef struct 
{
    unsigned int id;
    // The time of arrival at the parking lot, in timesteps.
    int time_arrival_park;
    // The time of arrival at the queue, in timesteps.
    int time_arrival_queue;
    // The duration of parking, in timesteps.
    int time_park_duration;
}Car;

/**
 * @brief Initialize a new car with random ID and park duration
 * 
 * @param params[in] Input parameters
 * @return Car Newly initialized car
 */
Car init_new_car(InputParams params);

/**
 * @brief Get a new unique ID for Car
 *
 * Should never return the same ID twice.
 *
 * Internally, a static variable is incremented and returned every call, so the
 * returned value will always increase.
 * 
 * @return int New unique ID
 */
int get_unique_id();

/**
 * @brief Get a random park duration for a new car
 *
 * Returns a random int between 1 and MAX_PARK_TIME. The latter being the
 * maximum allowed park time for a car defined by the input parameters
 * 
 * @param params[in] Input parameters
 * @return int Number of timesteps that the car wants to park for
 */
int random_park_duration(InputParams params);

#endif
