#ifndef H_SIMULATION
#define H_SIMULATION

// TODO: Define proper array for as parking_lot
typedef void* ParkingLot;
// TODO: Define proper Queue struct for cars
typedef void* QueueCars;

// TODO: Replace placeholder with proper struct definition
struct Car;

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
 */
void remove_due_cars(unsigned int current_step, ParkingLot parking_lot);

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
 */
void park_waiting_cars(ParkingLot parking_lot, QueueCars waiting_cars);

/**
 * @brief Randomly enqueue a new car to `waiting_cars`
 *
 * Every time step there is a random chance that a new car with a random park
 * duration will want to enter the parking lot. This function randomly decides
 * whether to create and enqueue a new car, or to do nothing (0 new arrivals).
 * 
 * @param waiting_cars[out] Current simulation parking_lot
 */
void get_new_cars_arriving(QueueCars waiting_cars);

/**
 * @brief Determine whether there are free spots in `parking_lot`
 * 
 * @param parking_lot[in] Given parking lot
 * @return int (boolean) whether there is at least one free spot
 */
int room_available(ParkingLot parking_lot);

/**
 * @brief Find any empty free spot in `parking_lot`
 * 
 * In case there are no free spots, return -1. Otherwise return the index of
 * a free spot.
 *
 * @param parking_lot[in] Given parking lot 
 * @return int Index to a free parking space
 */
int find_empty_space(ParkingLot parking_lot);

// TODO: The functions below should maybe be in other headers (e.g. Car.h)

/**
 * @brief Initialize a new car with random ID and park duration
 * 
 * @return Car Newly initialized car
 */
Car init_new_car();

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
 * @return int Number of timesteps that the car wants to park for
 */
int random_park_duration();

/**
 * @brief Return a random float between 0.0 (inclusive) and 1.0 (exclusive)
 * 
 * Uses `rand()` internally so uses the seed set by `srand()`
 *
 * @return float Random float between 0 and 1
 */
float frand();

#endif
