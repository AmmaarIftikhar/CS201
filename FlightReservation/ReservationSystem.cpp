/*Ammaar Iftikhar
  Section1
  21901257*/

#include "ReservationSystem.h"
#include "Flight.h"
#include "Aircraft.h"
#include <iostream>
#include <string>

using namespace std;

ReservationSystem::ReservationSystem(){

   // create an array of size zero
   totalFlights = 0;
   currentFlights = 0;
   flights = NULL;                    // **resize the array when total size becomes greater than current
}

ReservationSystem::~ReservationSystem(){
   delete [] flights;
}

void ReservationSystem::addFlight( const int flightNo,
                                   const int rowNo, const int seatNo){

   // CHECKS FOR FLIGHT WITH THE SAME ID
   for( int i = 0; i < currentFlights; i++){
      if( flights[i].getFlightID() == flightNo){
         cout<< "Invalid flight ID. A flight with similar id already exists. TRY AGAIN!"<< endl;
         return;
      }                                            // terminates the method
   }

   // CHECKS IF THERE IS AN ARRAY
   if( flights == NULL){
      flights = new Flight[++totalFlights];
   }

   // ADDS THE FLIGHT
   if( currentFlights < totalFlights){
      ( flights[currentFlights++]).setData( flightNo, rowNo, seatNo);
   }
   else{
       updateFlightArray();      // increase the size of the flight array
      ( flights[currentFlights]).setData( flightNo, rowNo, seatNo);
      currentFlights++;
   }

}

void ReservationSystem::cancelFlight( const int flightNo){

   // CHECKS FOR THE FLIGHT
   int i{0};
   bool found{false};
   if( flights == NULL)
      return;

   while( i < currentFlights){
      if( !found && flightNo == flights[i].getFlightID()){
         found = true;
         if( currentFlights == 0){
            delete [] flights;
            flights = NULL;
            return;
         }
         removeFlight( i);
      }
      i++;
   }
   if( !found)
      cout<< "No such flight exists.\n";
}

void ReservationSystem::showAllFlights(){
         cout<< "Flights currently operated\n";
   for( int i = 0; i < currentFlights; i++){

      cout<< "Flight ID: "<< flights[i].getFlightID();
      flights[i].displayAvailableSeats();
      cout<< endl;
   }
   cout<< "\n\n";
}

void ReservationSystem::showFlight( const int flightNo){
    for ( int i = 0; i < currentFlights; i++){
        if ( flights[i].getFlightID() == flightNo){
            flights[i].displaySeats();
            return;
        }
    }
    cout<< "FLIGHT DOES NOT EXIST!\n";
}

void ReservationSystem::cancelReservation( int id){
   int flightID{ id / 10000};

   int i{0};
   while ( i < currentFlights){
      if ( flightID == flights[i].getFlightID()){
         flights[i].cancelReservation( id);
         return;
      }
      i++;
   }
   cout<< "NO RESERVATION WITH ID = "<< id << " EXISTS.\n\n";
}

int ReservationSystem::makeReservation( const int flightNo, const int numPassengers,
                                            const int *seatRow, const char *seatCol){
   for ( int i = 0; i < currentFlights; i++){
      if ( flights[i].getFlightID() == flightNo){
         return flights[i].reserveSeats( numPassengers, seatRow, seatCol);
      }
   }
}

void ReservationSystem::showReservation( const int id){

   for ( int i = 0; i < currentFlights; i++){
      if ( flights[i].getFlightID() == ( id / 10000)){
         flights[i].displayReservation( id % 10000);
         return;
      }
   }
   cout<< "NO RESERVATION WITH ID = "<< id << " EXISTS.\n\n";
}

// UPADATES THE FLIGHTS ARRAY SO THAT MORE
// ELEMENTS CAN BE ADDED
void ReservationSystem::updateFlightArray(){
   Flight* temp = new Flight[2 * totalFlights];
   totalFlights *= 2;

   for( int i = 0; i < currentFlights; i++)
      temp[i] = flights[i];                 // OVERLOADED ASSIGNMENT OPERATOR IS CALLED
   delete [] flights;
   flights = temp;
}

// CHANGES THE ARRAY AND REMOVES THE ELEMENT
// FROM THE ARRAY
void ReservationSystem::removeFlight( const int& ind){
   Flight* temp = new Flight[currentFlights - 1];

   int index1 = 0;
   for( int i = 0; i < currentFlights; i++){
      if( i  == ind)
         continue;
      temp[index1++] = flights[i];
   }
   delete [] flights;
   flights = temp;
   currentFlights--;
}
