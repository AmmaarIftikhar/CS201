/* Ammaar Iftikhar
   21901257
   Section 1*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Flight.h"
#include "FlightMap.h"
#include "Stack.h"
#include "ListF.h"
#include "ListP.h"
using namespace std;

FlightMap::FlightMap( const string cityFile, const string flightFile){
    // variable initialisation
   length = 0;
   head = NULL;

   string text, origin, dest, id, price;
   ifstream inputFile;

   //Open the stream for the input file
   inputFile.open( cityFile.c_str(), ios_base::in);

   // count the cities form the city file
   while ( inputFile.eof() == false){
      getline( inputFile, text, '\n');
      length++;
   }
   inputFile.close();

   // get cities form the city file
   inputFile.open( cityFile.c_str(), ios_base::in);

   // create a neighbor list array
   neighborList = new ListF[length];

   int i{0};
   while ( inputFile.eof() == false){
      getline( inputFile, text, '\n');
      (neighborList + i)->insert(1, text);
      i++;
   }
   inputFile.close();

   // write the neighbors and other information of the city
   inputFile.open( flightFile.c_str(), ios_base::in);

   // read the  data from the file
   while( inputFile.eof() == false){
      getline( inputFile, origin, ',');
      getline( inputFile, dest, ',');
      getline( inputFile, id, ',');
      getline( inputFile, price, '\n');
      edge* temp = new edge;
      temp->next = head;
      head = temp;
      head->fnl = dest;
      head->strt = origin;
      int i, p;
      i = atoi(id.c_str());
      p = atoi(price.c_str());

      Flight f( origin, dest, i, p);
      flights.insert( 1, f);

      for( int t = 0; t < length; t++){
         string temp;
         neighborList[t].retrieve( 1, temp);

         if( temp == origin){
            neighborList[t].insert( 2, dest);
         }
      }
   }
}

FlightMap::~FlightMap(){
}

void FlightMap::displayAllCities() const{
   int index{0};
   while( index < length){
      string temp;
      neighborList[index].retrieve( 1, temp);
      cout<< temp<< endl;
      index++;
   }
}

// presence of infinite loop
void FlightMap::displayFlightMap() const{
   int index{ 0};

   while( index < length){
      string temp;

      neighborList[index].retrieve( 1, temp);
      cout<< temp<< " -> ";
      for( int i = 2; i <= neighborList[index].getLength(); i++){
         string temp;
         neighborList[index].retrieve( i, temp);
         cout<< temp<< ", ";
      }
      cout<< endl;
      index++;
   }
}

// presence of infinite loop
void FlightMap::displayAdjacentCities( const string cityName) const{
   // if departure city is the destination city
   int index{0};
   string temp;
   // neighborList[index].retrieve(1, temp);

   while( index < length){
      neighborList[index].retrieve(1, temp);
      if( temp == cityName){
         break;
      }
      index++;
   }

   cout<< temp<< "->";
   for( int i = 2; i <= neighborList[index].getLength(); i++){
      neighborList[index].retrieve( i, temp);
      cout<< temp<< ", ";
   }
   cout<< endl;
}

void FlightMap::findFlights( const string deptCity, const string destCity) const{
}

void FlightMap::findLeastCostFlight( const string deptCity, const string destCity ) const{
}
void FlightMap::runFlightRequests( const string requestFile) const{
   string origin, dest;
   ifstream inputFile;

   //Open the stream for the input file
   inputFile.open( requestFile.c_str(), ios_base::in);

   // count the cities form the city file
   while ( inputFile.eof() == false){
      getline( inputFile, origin, ',');
      getline( inputFile, dest, '\n');
      findFlights( origin, dest);
   }
   inputFile.close();
}

int FlightMap::getIndex( const string f) const{
   for( int i = 0; i < length; i++){
      string temp;
      neighborList[i].retrieve( 1, temp);

      // store the dept city address and exit the loop
      if( temp == f){
         return i;
      }
   }
   return -1;
}

FlightMap::edge* FlightMap::getNode( const string dept, const string arrvl) const{
   edge* cur = head;
   while( cur != NULL){
      if( cur->strt == dept && cur->fnl == arrvl){
         return cur;
      }
      cur = cur->next;
   }
   return NULL;
}

int FlightMap::getFlightIndex( const string ori, const string dest) const{
   for( int i = 1; i <= flights.getLength(); i++){
      Flight temp;
      flights.retrieve( i, temp);
      if( temp.getOrigin() == ori && temp.getDestination() == dest){
         return i;
      }
   }
   return -1;
}
