#ifndef RESERVATION_H
#define RESERVATION_H

#include "Flight.h"
#include <cstddef>
class Reservation{

public:
    Reservation( int = 0, int = 0,const int* = NULL, const char* = NULL);         // create the reservation based on the information sent by the R.S.
    Reservation( Reservation&);
    ~Reservation();
    void displayReservation() const;
    void displayReservedSeats() const;
    void setReservation( int, int, const int*, const char*);
    int getReservationId() const;
    Reservation& operator=( const Reservation&);
    void getSeats( int*&, char*&, int&);

private:
    int reservationId;
    int totalSeats;
    int* rows;
    char* columns;
};

#endif // RESERVATION_H
