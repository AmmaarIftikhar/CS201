#ifndef FLIGHT_H
#define FLIGHT_H

#include "Reservation.h"
#include "Aircraft.h"
#include <string>
#include <iostream>

class Flight{
public:
   Flight( const int = 0, const int = 0, const int = 0);
   ~Flight();
   int getFlightID() const;
   int getRows() const;
   int getColumns() const;
   void setData( const int, const int, const int);
   int reserveSeats( const int numPassengers,
                     const int *seatRow, const char *seatCol);       // call reserve seat and reserve all the seats one by one
                                                                     // return 0 if failed return 1 if success
   void cancelReservation( const int id);
   void displayReservation( const int);         // return 0 if failed return 1 if success
   void displaySeats();
   void displayAvailableSeats();
   Flight& operator=( const Flight& rightFlight);

private:
   int flightId;
   Aircraft* aircraft;
   int* seats;             // 0 represents the seat is empty and 1 full
   Reservation* resObj;
   int totalReservations;
   int reserveSeat( const int, const char);
};

#endif

