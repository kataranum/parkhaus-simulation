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
```
*/
void free_parking_lot(ParkingLot parking_lot);

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
int room_available(const ParkingLot *p_parking_lot) {
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
int find_empty_space(const ParkingLot *p_parking_lot) {
    // TODO
}
