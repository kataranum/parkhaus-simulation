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
 * @param current_step 
 * @param parking_lot 
 */
void remove_due_cars(unsigned int current_step, ParkingLot parking_lot);

void park_waiting_cars(ParkingLot parking_lot, QueueCars waiting_cars);

void get_new_cars_arriving(QueueCars waiting_cars);

int room_available(ParkingLot parking_lot);

Car init_new_car();
int get_unique_id();

float frand();

#endif
