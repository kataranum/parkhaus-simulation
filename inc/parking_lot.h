/**
 * File: parking_lot.h
 * Description: This file contains the ParkingLot struct and ParkingLot functions.
 */

#ifndef PARKING_LOT_H
#define PARKING_LOT_H

#include <car.h>

/**
 * @brief All values related to a parking lot.
 */
typedef struct 
{
    /// Pointer to array
    Car *p_array;
    /// Length of the array
    unsigned int length;
} ParkingLot;

/**
 * @brief Initialize a new parking lot with given length
 * 
 * This array is allocated on the heap, so it must be free'd after use with
 * `free_parking_lot()`.
 * 
 * @param[in] length Length of the parking lot
 * @return           Newly initialized parking lot
 */
ParkingLot init_parking_lot(unsigned int length);

/**
 * @brief Free the memory allocated for the parking lot
 * 
 * @param[inout] parking_lot Parking lot to delete
 */
void free_parking_lot(ParkingLot *p_parking_lot);

/**
 * @brief Get the amount of occupied parking spots
 * 
 * @param[in] parking_lot Given parking lot
 * @return                Amount of occupied parking spots
 */
unsigned int get_occupancy(ParkingLot parking_lot);

/**
 * @brief Determine whether there are free spots in the parking lot
 * 
 * @param[in] parking_lot Given parking lot
 * @return                Whether at least 1 spot is available
 */
bool room_available(ParkingLot parking_lot);

/**
 * @brief Find any empty free spot in the parking lot
 * 
 * In case there are no free spots, return -1. Otherwise return the index of
 * a free spot.
 *
 * @param[in] parking_lot Given parking lot 
 * @return                Index to a free parking space or -1 if no space is available
 */
int find_empty_space(ParkingLot parking_lot);

#endif
