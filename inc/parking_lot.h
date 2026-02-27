#ifdef PARKING_LOT_H
#define PARKING_LOT_H

/**
 * @brief This struct is a definiton of a parking lot, which contains an array of cars and the length of the array.
 */
typedef struct 
{
    Car *p_array;
    unsigned int length;
}ParkingLot;

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

#endif