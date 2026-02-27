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

#endif
