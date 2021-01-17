#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

// Preprocessor directive
#include <string>
#include "Flight.h"
#include "Reservation.h"

class ReservationSystem{
public:
ReservationSystem();
~ReservationSystem();
void addFlight( const int flightNo, const int rowNo, const int seatNo);
void cancelFlight( const int flightNo);
void showAllFlights();
void showFlight( const int flightNo);
int makeReservation( const int flightNo, const int numPassengers,
                     const int *seatRow, const char *seatCol);
void cancelReservation( const int resCode);
void showReservation( const int resCode);
void updateFlightArray();
void removeFlight( const int&);
private:
  Flight* flights;
  int totalFlights;
  int currentFlights;
};

#endif

