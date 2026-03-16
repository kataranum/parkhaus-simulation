#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "../inc/parking_lot.h"
#include "../inc/car.h"

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

}

void test_find_empty_space()
{
    ParkingLot lot = init_parking_lot(5);

    int index = find_empty_space(lot);
    assert(index == 0);

    free_parking_lot(&lot);

}

void test_get_occupancy_after_parking()
{
    ParkingLot lot = init_parking_lot(5);

    Car car;

    lot.p_array[0] = car;

    int occ = get_occupancy(lot);
    assert(occ == 1);

    free_parking_lot(&lot);

}

void test_free_parking_lot()
{
    ParkingLot lot = init_parking_lot(5);

    free_parking_lot(&lot);

    assert(lot.p_array == NULL);
    assert(lot.length == 0);

}

// Main Funktion
int main()
{
    test_init_parking_lot();
    test_get_occupancy_empty();
    test_room_available();
    test_find_empty_space();
    test_get_occupancy_after_parking();
    test_free_parking_lot();

    printf("\nAlle Tests bestanden!\n");

    return 0;
}
