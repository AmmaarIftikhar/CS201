/*Ammaar Iftikhar
  Section1
  21901257*/

#include "Flight.h"
#include "Reservation.h"
#include <iostream>
using namespace std;

Reservation::Reservation( int id, int reserSize, const int* ro, const char* co)
                    : totalSeats{reserSize},    reservationId{id}{
   rows = new int[reserSize];
   columns = new char[reserSize];

   for( int i = 0; i < reserSize; i++){
      rows[i] = ro[i];
      columns[i] = co[i];
   }
}

Reservation::~Reservation(){
    if ( rows != NULL && columns != NULL)
    {
       delete [] rows;
       delete [] columns;
    }
}


void Reservation::setReservation( int id,int reserSize,
                                  const int* ro, const char* co){
   totalSeats = reserSize;
   reservationId = id;
   rows = new int[reserSize];
   columns = new char[reserSize];

   for( int i = 0; i < reserSize; i++){
      rows[i] = ro[i];
      columns[i] = co[i];
   }
}

void Reservation::displayReservation() const{
   cout<< "The reservation id is: "<<reservationId<< endl;       // use the pointer call!
   // PRINT THE SEATS
   cout<< "The seats reserved are: \n";
   for( int i = 0; i < totalSeats; i++){
      cout<< rows[i]<< (char)columns[i];
      if( i < (totalSeats - 1))
         cout<< ", ";
      else
         cout<< endl;
   }
}

void Reservation::displayReservedSeats() const{
    for ( int i = 0; i < totalSeats; i++){
        cout << "Row: "<< rows[i]<< " Column" << columns[i]<<endl;
    }
}

/** this is the overloaded = equal to operator
    this copies the values of one object onto
    another--creates a shallow copy**/
Reservation& Reservation::operator=( const Reservation& copyObject){
   this->reservationId = copyObject.reservationId;
   this->totalSeats    = copyObject.totalSeats;
   this->columns       = copyObject.columns;
   this->rows          = copyObject.rows;
   delete             [] copyObject.columns;
   delete             [] copyObject.rows;
}

int Reservation::getReservationId() const{
   return reservationId;
}

// This method gives the user the access to
// the rows and columns of the reservation class
void Reservation::getSeats( int*& r, char*& c, int& s){
   r = new int[totalSeats];
   c = new char[totalSeats];
   s = totalSeats;
   for( int i = 0; i < totalSeats; i++){
      r[i] = rows[i];
      c[i] = columns[i];
   }
}
