#ifndef H_SIMULATION
#define H_SIMULATION

// TODO: Define proper array for as parking_lot
typedef void* ParkingLot;
// TODO: Define proper Queue struct for cars
typedef void* QueueCars;

void remove_due_cars(unsigned int current_step, ParkingLot parking_lot);

void park_waiting_cars(ParkingLot parking_lot, QueueCars waiting_cars);

#endif
