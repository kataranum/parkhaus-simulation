/**
 * @file Central functions that implement the main simulation loop.
 */

#ifndef SIMULATION_H
#define SIMULATION_H

// TODO: Replace placeholder with proper struct definition
/// All variables that are given as input to the program
struct InputParams;

// TODO: Replace placeholder with proper struct definition
/// Storage for all data that evaluates statistics
struct Stats;

/**
 * @brief All data relevant for the simulation in one struct
 */
struct SimulationData {
    InputParams params;
    /** The current time step */
    unsigned int current_step;
    /** Pointer to all the statistics variables */
    Stats *p_stats;

    /** Current state of the parking lot array */
    ParkingLot parking_lot;
    /** Current queue of all cars waiting */
    QueueCars queue;
};

/**
 * @brief Run the entire simulation with the given parameters
 * 
 * The simulation uses `params` to determine behaviour, and saves all relevant
 * statistics in `p_stats`.
 *
 * @param params[in] Given input parameters
 * @param p_stats[in/out] Statistics data
 */
void run_simulation(InputParams params, Stats *p_stats);

/**
 * @brief Have cars over their max park time leave the parking lot
 * 
 * Every car has a set parking duration. After this time passed, the car must
 * leave the parking lot. This function takes care of that.
 *
 * This function also makes calls to statistics functions to mark the departure
 * in statistics.
 *
 * @param simulation_data[in] simulation_data
 */
void remove_due_cars(SimulationData simulation_data);

/**
 * @brief Move cars from the queue in the parking lot until the lot is full
 * 
 * The cars in `waiting_cars` are waiting for free spots in `parking_lot`. This
 * function will move cars from the queue into the lot until the lot is filled,
 * or the queue becomes empty. If the lot is full, the remaining cars in
 * `waiting_cars` remain in queue until next time step (or longer).
 *
 * @param simulation_data[in] simulation_data
 */
void park_waiting_cars(SimulationData simulation_data);

/**
 * @brief Randomly enqueue a new car to `waiting_cars`
 *
 * Every time step there is a random chance that a new car with a random park
 * duration will want to enter the parking lot. This function randomly decides
 * whether to create and enqueue a new car, or to do nothing (0 new arrivals).
 * 
 * @param simulation_data[in] simulation_data
 */
void get_new_cars_arriving(SimulationData simulation_data);

#endif
