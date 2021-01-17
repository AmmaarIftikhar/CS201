/* Ammaar Iftikhar
   21901257
   Section 1*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Flight.h"
#include "FlightMap.h"
#include "City.h"
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
      i = stoi( id);
      p = stoi( price);

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
   delete [] neighborList;

   edge* cur{ head};
   while( head != NULL){
      cur = head->next;
      head->next = NULL;
      delete head;
      head = NULL;
   }
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
   neighborList[index].retrieve(1, temp);

   while( temp != cityName && index < length){
      neighborList[++index].retrieve(1, temp);
   }

   cout<< temp<< "->";
   for( int i = 2; i <= neighborList[index].getLength(); i++){
      neighborList[index].retrieve( i, temp);
      cout<< temp<< ", ";
   }
   cout<< endl;
}

void FlightMap::findFlights( const string deptCity, const string destCity) const{
   edge* cur = head;
   int index, row{0};
   Stack path;
   ListF allPaths[length];

   // mark all elements false
   while( cur != NULL){
      cur->visited = false;
      cur = cur->next;
   }
   // find the index of the origin city
   index = getIndex( deptCity);

   // mark the city as visited.
   string top, prev;
   if( neighborList[index].getLength() < 2){
      cout<< "No possible way."<< endl;
      return;
   }
   else{
      prev = deptCity;
      neighborList[ index].retrieve( 2, top);
   }

   // an error exists
   cur = getNode( prev, top);
   cur->visited = true;
   prev = deptCity;
   path.push( prev);
   path.push( top);
   while( !path.isEmpty()){
      string nextPos;
      index = getIndex( top);
      bool allMrkd{ true};
      // check if all of the neighbors of the top city are marked
      for( int j = 2; j <= neighborList[index].getLength(); j++){
         string ele;
         neighborList[index].retrieve( j, ele);
         edge* edgeTemp = getNode( top, ele);
         if( !edgeTemp->visited){
            allMrkd = false;
            prev = top;
            top = ele;
            cur = getNode( prev, top);
            break;
         }
      }

      if( neighborList[index].getLength() <= 1 || allMrkd){
         cur->visited = true;
         path.pop();
      }
      else{
         // choose a destination, check if unvisited
         // if unvisited put on stack otherwise check other
         string h;
         cur->visited = true;
         path.push( top);
      }

      // there is an issue in this loop ********
      string d1;
      path.getTop( d1);
      if( d1 == destCity){
         Stack tStack;
         string a, b;

         path.pop( a);
         allPaths[row].insert( 1, a);
         cur->visited = true;
         path.getTop( a);

         while( a != deptCity){
            path.pop();
            allPaths[row].insert( 1, a);
            tStack.push( a);
            path.getTop( a);
         }

         allPaths[ row++].insert( 1, deptCity);
         while( !tStack.isEmpty()){
            tStack.pop( a);
            path.push( a);
         }
      }

      bool topCovered{ true};
      // issue from here --infinite loop   cleared
      // circular movement in the loops -- not cleared
      for( edge* tempCur = head; tempCur != NULL; tempCur = tempCur->next){
         // check if all neighbors of the dept are visited
         if( !tempCur->visited){
            topCovered = false;
            break;
         }
      }
      // if all the neighbors of the dept city have been visited exit loop by popping
      path.getTop( d1);
      if( d1 == deptCity && topCovered){
         path.pop();
      }
      else{
         path.getTop( top);
      }
   }

   if( row >= 1){

      cout<< "Request is to fly from "<< deptCity<< " to "<< destCity<< endl;
      for( int i = 0; i < row; i++){
         int totalPrice{0};
         for( int j = 1; j < allPaths[i].getLength(); j++ ){
            string from, to;
            int pos;
            Flight ntemp;
            allPaths[i].retrieve( j, from);
            allPaths[i].retrieve( j + 1, to);
            pos = getFlightIndex( from, to);
            flights.retrieve( pos, ntemp);
            ntemp.printInfo();
            totalPrice += ntemp.getPrice();
         }
         cout<< "The total cost of travel is: "<< totalPrice<< "\n"<< endl;
      }
   }
   else{
      cout<< "No paths found from "<< deptCity<< " to "<< destCity<< endl;
   }
}

//void FlightMap::findFlights( const string deptCity, const string destCity ) const{}
void FlightMap::findLeastCostFlight( const string deptCity, const string destCity )
const{
   edge* cur = head;
   int index, row{0};
   Stack path;
   ListF allPaths[length];

   // mark all elements false
   while( cur != NULL){
      cur->visited = false;
      cur = cur->next;
   }
   // find the index of the origin city
   index = getIndex( deptCity);

   // mark the city as visited.
   string top, prev;
   if( neighborList[index].getLength() < 2){
      cout<< "No possible way."<< endl;
      return;
   }
   else{
      prev = deptCity;
      neighborList[ index].retrieve( 2, top);
   }

   // an error exists
   cur = getNode( prev, top);
   cur->visited = true;
   prev = deptCity;
   path.push( prev);
   path.push( top);
   while( !path.isEmpty()){
      string nextPos;
      index = getIndex( top);
      bool allMrkd{ true};
      // check if all of the neighbors of the top city are marked
      for( int j = 2; j <= neighborList[index].getLength(); j++){
         string ele;
         neighborList[index].retrieve( j, ele);
         edge* edgeTemp = getNode( top, ele);
         if( !edgeTemp->visited){
            allMrkd = false;
            prev = top;
            top = ele;
            cur = getNode( prev, top);
            break;
         }
      }

      if( neighborList[index].getLength() <= 1 || allMrkd){
         cur->visited = true;
         path.pop();
      }
      else{
         // choose a destination, check if unvisited
         // if unvisited put on stack otherwise check other
         string h;
         cur->visited = true;
         path.push( top);
      }

      // there is an issue in this loop ********
      string d1;
      path.getTop( d1);
      if( d1 == destCity){
         Stack tStack;
         string a, b;

         path.pop( a);
         allPaths[row].insert( 1, a);
         cur->visited = true;
         path.getTop( a);

         while( a != deptCity){
            path.pop();
            allPaths[row].insert( 1, a);
            tStack.push( a);
            path.getTop( a);
         }

         allPaths[ row++].insert( 1, deptCity);
         while( !tStack.isEmpty()){
            tStack.pop( a);
            path.push( a);
         }
      }

      bool topCovered{ true};
      // issue from here --infinite loop   cleared
      // circular movement in the loops -- not cleared
      for( edge* tempCur = head; tempCur != NULL; tempCur = tempCur->next){
         // check if all neighbors of the dept are visited
         if( !tempCur->visited){
            topCovered = false;
            break;
         }
      }
      // if all the neighbors of the dept city have been visited exit loop by popping
      path.getTop( d1);
      if( d1 == deptCity && topCovered){
         path.pop();
      }
      else{
         path.getTop( top);
      }
   }
   int min{0};
   int indexFinal{-1};
   int totalPrice{0};
   if( row >= 1){

      cout<< "Request is to fly from "<< deptCity<< " to "<< destCity<< endl;
      for( int i = 0; i < row; i++){
         totalPrice = 0;
         for( int j = 1; j < allPaths[i].getLength(); j++ ){
            string from, to;
            int pos;
            Flight ntemp;
            allPaths[i].retrieve( j, from);
            allPaths[i].retrieve( j + 1, to);
            pos = getFlightIndex( from, to);
            flights.retrieve( pos, ntemp);
            ntemp.printInfo();
            totalPrice += ntemp.getPrice();
         }
         if( min == 0 || min > totalPrice){
            min = totalPrice;
            indexFinal = i;
         }
         cout<< "The total cost of travel is: "<< totalPrice<< "\n"<< endl;
      }

      cout<< "\nThe shortest path is ";
      for( int i = 1; i <= allPaths[indexFinal].getLength(); i++){
         string print;
         allPaths[indexFinal].retrieve( i, print);
         if( i < allPaths[indexFinal].getLength())
            cout<< print<< "-> ";
         else
            cout<< print<< "."<< " and it costs "<< totalPrice<<endl;
      }
   }
   else{
      cout<< "No paths found from "<< deptCity<< " to "<< destCity<< endl;
   }
}
void FlightMap::runFlightRequests( const string requestFile ) const{

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
