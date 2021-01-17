/* Ammaar Iftikhar
   21901257
   Section 1*/

#include <iostream>
#include "Flight.h"
#include <string>
using namespace std;

Flight::Flight( const string origin, const string destination, const int id, const int price){
   this->origin = origin;
   this->destination = destination;
   this->id = id;
   this->price = price;
}

Flight::Flight( const Flight& flight){
   this->id = flight.id;
   this->destination = flight.destination;
   this->origin = flight.origin;
   this->price  = flight.price;
}

string Flight::getDestination() const{
   return destination;
}

string Flight::getOrigin() const{
   return origin;
}

int Flight::getId() const{
   return id;
}

int Flight::getPrice() const{
   return price;
}

void Flight::setDestination( const string dest){
   destination = dest;
}

void Flight::setOrigin( const string ori){
   origin = ori;
}

void Flight::setPrice( const int cost){
   price = cost;
}

void Flight::setId( const int id){
   this->id = id;
}

void Flight::printInfo() const{
   cout<< "Flight #"<< id<< " from "<< origin<< " to "<< destination<<
          " Cost: "<< price<< " TL"<< endl;
}
