#ifndef H_SIMULATION
#define H_SIMULATION

// TODO: Define proper array for as parking_lot
struct ParkingLot;
// TODO: Define proper Queue struct for cars
struct QueueCars;

// TODO: Replace placeholder with proper struct definition
struct Car;

// TODO: Replace placeholder with proper struct definition
/// All variables that are given as input to the program
struct InputParams;

// TODO: Replace placeholder with proper struct definition
/// Storage for all data that evaluates statistics
struct Stats;

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
 * @param current_step[in] Current simulation time step 
 * @param parking_lot[in/out] Current simulation parking lot
 * @param stats[in/out] Statistics data
 */
void remove_due_cars(unsigned int current_step, ParkingLot *p_parking_lot, Stats *p_stats);

/**
 * @brief Move cars from the queue in the parking lot until the lot is full
 * 
 * The cars in `waiting_cars` are waiting for free spots in `parking_lot`. This
 * function will move cars from the queue into the lot until the lot is filled,
 * or the queue becomes empty. If the lot is full, the remaining cars in
 * `waiting_cars` remain in queue until next time step (or longer).
 *
 * @param parking_lot[in/out] Current simulation parking lot
 * @param waiting_cars[in/out] Current simulation car queue
 * @param stats[in/out] Statistics data
 */
void park_waiting_cars(ParkingLot *p_parking_lot, QueueCars *p_waiting_cars, Stats *p_stats);

/**
 * @brief Randomly enqueue a new car to `waiting_cars`
 *
 * Every time step there is a random chance that a new car with a random park
 * duration will want to enter the parking lot. This function randomly decides
 * whether to create and enqueue a new car, or to do nothing (0 new arrivals).
 * 
 * @param params[in] Input parameters
 * @param waiting_cars[in/out] Current simulation car queue
 * @param stats[in/out] Statistics data
 */
void get_new_cars_arriving(InputParams params, QueueCars *p_waiting_cars, Stats *p_stats);

/**
 * @brief Determine whether there are free spots in `parking_lot`
 * 
 * @param parking_lot[in] Given parking lot
 * @return int (boolean) whether there is at least one free spot
 */
int room_available(const ParkingLot *p_parking_lot);

/**
 * @brief Find any empty free spot in `parking_lot`
 * 
 * In case there are no free spots, return -1. Otherwise return the index of
 * a free spot.
 *
 * @param parking_lot[in] Given parking lot 
 * @return int Index to a free parking space
 */
int find_empty_space(const ParkingLot *p_parking_lot);

// TODO: The functions below should maybe be in other headers (e.g. Car.h)

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

/**
 * @brief Return a random float between 0.0 (inclusive) and 1.0 (exclusive)
 * 
 * Uses `rand()` internally so uses the seed set by `srand()`
 *
 * @return float Random float between 0 and 1
 */
float frand();

#endif
