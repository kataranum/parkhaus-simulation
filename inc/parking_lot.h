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

#endif