/**
 * File: car.h
 * Description: This file contains the Car struct and Car functions.
 */

#ifndef CAR_H
#define CAR_H

#include <user_input.h>
#include <stdbool.h>

/**
 * @brief All values related to a car.
 * 
 * This struct is a definition of a car, which contains the id of the car,
 * the time of arrival at the parking lot, the time of arrival at the queue and the duration of parking.
 * 
 * An id of -1 is used to indicate an empty parking space and other fields are ignored in this case.
 */
typedef struct 
{
    /// ID of car; "-1" indicating an invalid or "empty" car (in the context of parking_lot)
    int id;
    /// The time of arrival at the parking lot, in timesteps.
    int time_arrival_park;
    /// The time of arrival at the queue, in timesteps.
    int time_arrival_queue;
    /// The duration of parking, in timesteps.
    int time_park_duration;
} Car;

/**
 * @brief Initialize a new car with random ID and park duration
 * 
 * @param[in] params Input parameters
 * @return           Newly initialized car
 */
Car init_new_car(InputParams params);

/**
 * @brief Initialize a car flagged as empty
 *
 * @return Car with ID set to -1 and all other fields to reasonable defaults
 */
Car init_empty_car();

/**
 * @brief Get a new unique ID for Car
 *
 * Should never return the same ID twice.
 *
 * Internally, a static variable is incremented and returned every call, so the
 * returned value will always increase.
 * 
 * @return New unique ID
 */
int get_unique_id();

/**
 * @brief Get a random park duration for a new car
 *
 * Returns a random int between 1 and MAX_PARK_TIME. The latter being the
 * maximum allowed park time for a car defined by the input parameters
 * 
 * @param[in] params Input parameters
 * @return           Number of timesteps that the car wants to park for
 */
int random_park_duration(InputParams params);

/**
 * @brief Determine whether a parking space is empty
 * 
 * A parking space is empty if the id of the car is negative.
 * 
 * @param[in] car Car to check
 * @return        Whether car is invalid and interpreted as empty
 */
bool car_empty(Car car);

#endif
