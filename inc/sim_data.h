/**
 * File: sim_data.h
 * Description: Struct definitions used for the simulation loop and statistics
 */
#ifndef SIM_DATA_H
#define SIM_DATA_H

#include <stdio.h>
#include <parking_lot.h>
#include <car_queue.h>
#include <user_input.h>

/**
 * @brief All values relevant for statistics calculations
 */
typedef struct
{
    FILE *log_file;

    /* Occupancy */
    int sum_occupancy;

    /* Waiting time */
    int sum_waiting_time;

    /* Queue statistics */
    int sum_queue_length;
    unsigned int max_queue_length;

    /* Full occupancy */
    int full_occupancy_steps;

    /* Finished cars */
    int finished_cars;
} Statistics;

/**
 * @brief All data relevant for the simulation in one struct
 */
typedef struct
{
    InputParams params;
    /** The current time step */
    unsigned int current_step;
    /** Pointer to all the statistics variables */
    Statistics *p_stats;

    /** Current state of the parking lot array */
    ParkingLot parking_lot;
    /** Current queue of all cars waiting */
    CarQueue waiting_cars;
} SimulationData;

#endif
