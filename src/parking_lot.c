#include "../inc/parking_lot.h"

/*
```PSEUDOCODE
ParkingLot parking_lot;
parking_lot.array = malloc(length * sizeof(Car));
IF parking_lot.array == NULL:
    EXIT with error code
END IF
parking_lot.length = length;
RETURN parking_lot
```
*/
ParkingLot init_parking_lot(unsigned int length);

/*
```PSEUDOCODE
free(parking_lot.array);
parking_lot.array = NULL;
parking_lot.length = 0;
```
*/
void free_parking_lot(ParkingLot *p_parking_lot) {
    // TODO
}

/*
```PSEUDOCODE
int occupancy = 0;
FOR i IN 0 TO parking_lot.length:
    car = parking_lot.array[i];

    IF !is_empty(car):
        occupancy++;
    END IF
END FOR

RETURN occupancy;
```
*/
int get_occupancy(ParkingLot parking_lot) {
    // TODO
}

/*
```PSEUDOCODE
FOR i IN 0 TO parking_lot.length:
    car = parking_lot.array[i];

    IF is_empty(car):
        RETURN True;
    END IF
END FOR

RETURN False;
```
*/
int room_available(ParkingLot parking_lot) {
    // TODO
}

/*
```PSEUDOCODE
FOR i IN 0 TO parking_lot.length:
    car = parking_lot.array[i];

    IF is_empty(car):
        RETURN i;
    END IF
END FOR

RETURN -1
```
*/
int find_empty_space(ParkingLot parking_lot) {
    // TODO
}
