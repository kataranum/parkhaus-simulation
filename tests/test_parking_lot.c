#include <assert.h>
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
