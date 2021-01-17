/*Ammaar Iftikhar
  Section1
  21901257*/

#include <iostream>
#include "Aircraft.h"
#include "Flight.h"
#include "Reservation.h"
#include <string>
#include <cmath>
using namespace std;

Flight::Flight( const int id, const int rows, const int columns)
        :flightId{id}{
   totalReservations = 0;
   // check!
   if ( rows <= 0 || columns <= 0){
      seats = NULL;
      aircraft = NULL;
      resObj = NULL;
   }
   else
   {
      seats        = new int[ rows * columns]{};          // initializes all the elements to zero
      aircraft     = new Aircraft( rows, columns);
      resObj       = new Reservation[rows * columns];
   }

}

// this is the class destructor
Flight::~Flight(){
   if( seats != NULL){
      delete [] aircraft;
      delete [] seats;
      delete [] resObj;
   }
}

// this method returns the flight Id
// in the flight*/
int Flight::getFlightID() const{
   return flightId;
 }

// this method returns the number of
//   rows in the flight
int Flight::getRows() const{
   return aircraft->getRow();
}

// this method returns the number of
// columns in the flight*/
int Flight::getColumns() const{
   return aircraft->getColumn();
}

// this method is responsible makes changes to the
// flight object
void Flight::setData( const int id, const int ro, const int co){
    if ( seats == NULL)
    {
       flightId     = id;
       aircraft     = new Aircraft( ro, co);
       resObj       = new Reservation[ro * co];
       seats        = new int[ro * co]{};
    }

   cout<< "A flight with id "<< getFlightID()
                             << " has just been added."<< endl;
}

// this method reserves seats on a plane
// and checks if the seats are available
int Flight::reserveSeats( const int numPassengers,
                          const int *seatRow, const char *seatCol){

   // check availability of all the seats
   for ( int i = 0; i < numPassengers; i++){
      int col = (int)seatCol[i] - 65;
      int seatReq{ col * seatRow[i] + col};
      if( col < 0 || col > aircraft->getColumn()){
         // if invalid col argument
         cout<< "There is an invalid value for the column.\n";
         return -1;
      }
      else if( seatRow[i] < 0 || seatRow[i] > aircraft->getRow()){
         cout<< "There is an invalid value for the row.\n";
         // if invalid row argument
         return -1;
      }
      else if ( seats[ seatReq] == 1){
         // if seat is not available
         cout<< "Seat already booked!"<< endl;
         return -1;
      }
   }

   // reserve all the seats
   for ( int i = 0; i < numPassengers; i++){
      int col{ (int)seatCol[i] - 65};
      int seatReq{ aircraft->getColumn() * ( seatRow[i] - 1) + col};
      seats[seatReq] = 1;
      // if ( reserveSeat( seatRow[i], (int)seatCol[i] - 65) == -1)    return -1;
   }

   int tempId = flightId * 10000 + aircraft->getColumn() * seatRow[0] + ((int)seatCol[0] - 65);
   resObj[totalReservations].setReservation( tempId, numPassengers,
                                             seatRow, seatCol);
   return resObj[totalReservations++].getReservationId();
}

// this method cancels the reservation
// with the id
void Flight::cancelReservation(const int id){
   bool found{false};
   // search for registration
   for ( int i = 0; i < totalReservations; i++){
      if( resObj[i].getReservationId() == id){
         found = true;
         totalReservations--;     // an issue
      }

      if(found){
         int *ro, total;
         char *col;
         resObj[i].getSeats( ro, col, total);
         // open  the seats
         for( int i = 0; i < total; ++i){
            int co = (int)col[i] - 65;
            int seatReq{ aircraft->getColumn() * ( ro[i] - 1) + co};
            seats[seatReq] = 0;
         }

         resObj[i] = resObj[i + 1];
      }
   }
}

// this method displays the a reservation with reservation id = id
void Flight::displayReservation(const int id){
    // search for registration
    for( int i = 0; i < totalReservations; i++){
            if( resObj[i].getReservationId() == id + flightId * 10000){
               resObj[i].displayReservation();
               break;
        }
    }
}

void Flight::displayAvailableSeats(){
   // VARIABLE DECLARATION AND INITIALISATION
   int available{0};
   int total{aircraft->getColumn() * aircraft->getRow()};

   // COUNTING THE NUMBER OF AVAILBLE SEATS
   for( int i = 0; i < total; i++){
      if( seats[i] == 0)   available++;
   }
   cout<< ". (There are "<< available<< " seats available.)";
}

// this method displays the seats of  particular flight
void Flight::displaySeats(){
   // Variable declaration and initialization
   int ro{aircraft->getRow()};
   int co{ aircraft->getColumn()};

   // print the column names
   cout<< "  ";
   for( int i = 0; i < co; ++i){
      cout<< " "<< (char)( 65 + i)<< " ";
   }
   cout<< endl;

   // print the row followed by the availability per row
   for( int i = 0; i < ro; ++i){
      cout<< i + 1<< " ";

      // printing the seats of the i row
      for( int j = 0; j < co; ++j){
         int seatReq{ co * i + j};
         if( seats[seatReq] == 0)
            cout<< " o ";
         else
            cout<< " x ";
      }
      cout<< endl;
   }
}

Flight& Flight::operator=( const Flight& rightFlight){

   // VARIABLE DECLARATION AND INITIALIZATION
   int ro{rightFlight.aircraft->getRow()};
   int co{rightFlight.aircraft->getColumn()};
   seats = new int[ro * co];
   resObj = new Reservation[ro * co];

   // COPYING DATA
   this->flightId = rightFlight.flightId;
   this->aircraft = new Aircraft( ro, co);

   for( int j = 0; j < abs(ro * co); j++){
      this->seats[j] = rightFlight.seats[j];
   }

   for( int i = 0; i < totalReservations; ++i){
      int* roArr;
      char* coArr;
      int reSize;
      rightFlight.resObj[i].getSeats( roArr, coArr, reSize);
      reserveSeats( reSize, roArr, coArr);
   }
}
