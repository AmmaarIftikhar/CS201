/* Ammaar Iftikhar
   21901257
   Section 1*/

#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H
#include <iostream>
#include "Flight.h"
#include "ListF.h"
#include "ListP.h"
#include <string>

class FlightMap {
public:
FlightMap( const string cityFile, const string flightFile );
~FlightMap();
void displayAllCities() const;
void displayAdjacentCities( const string cityName ) const;
void displayFlightMap() const;
void findFlights( const string deptCity, const string destCity ) const;
void findLeastCostFlight( const string deptCity, const string destCity )
const;
void runFlightRequests( const string requestFile ) const;

private:
   struct edge{
      string strt;
      string fnl;
      edge*  next;
      bool   visited;
   };
   ListF*       neighborList;
   ListP             flights;
   int                length;
   edge*                head;
   int getIndex( const string) const;
   edge* getNode( const string, const string) const;
   int getFlightIndex( const string, const string) const;
};

#endif


