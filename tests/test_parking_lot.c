#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "../inc/parking_lot.h"

// Test init_parking_lot 
void test_init_parking_lot()
{
    ParkingLot lot = init_parking_lot(5);

    assert(lot.length == 5);
    assert(lot.p_array != NULL);

    free_parking_lot(&lot);
}

/* Test get_occupancy on empty parking lot */
void test_get_occupancy_empty()
{
    ParkingLot lot = init_parking_lot(5);

    int occ = get_occupancy(lot);
    assert(occ == 0);

    free_parking_lot(&lot);
}

void test_room_available()
{
    ParkingLot lot = init_parking_lot(5);

    assert(room_available(lot) == true);

    free_parking_lot(&lot);

    printf("test_room_available passed\n");
}
