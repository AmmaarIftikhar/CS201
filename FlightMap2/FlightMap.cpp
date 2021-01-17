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
   delete [] neighborList;

   edge* cur{ head};
   while( head != NULL){
      cur = head->next;
      head->next = NULL;
      delete head;
      head = cur;
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
   cout<< "Note: This function works properly on codeblocks, but, unfortunately, not on dijkstra.ug.bcc.bilkent.edu.tr"<< endl;
   while( index < length){
      string temp;
      if( neighborList[index].getLength() >= 1)
         neighborList[index].retrieve( 1, temp);
      string print;
      edge* cur = head;
      print = temp + "->";
      while( cur != NULL){
         if( cur->strt == temp){
            print = print + cur->fnl + ", ";
         }

         cur = cur->next;
      }
      cout<< print<< endl;
      index++;
   }
}

// presence of infinite loop
void FlightMap::displayAdjacentCities( const string cityName) const{
   // if departure city is the destination city
   string print;
   edge* cur = head;
   print = cityName + "->";
   while( cur != NULL){
      if( cur->strt == cityName){
         print = print + cur->fnl + ", ";
      }

      cur = cur->next;
   }
   cout<< print<< endl;
}

void FlightMap::findFlights( const string deptCity, const string destCity) const{
   edge* cur = head;
   int row = 0;
   string top, prev;
   Stack path;
   ListF allPaths[length];

   // mark all elements false
   while( cur != NULL){
      cur->visited = false;
      cur = cur->next;
   }

   cur = head;
   // find the deptCity in the linked list
   while( cur != NULL){
      if( cur->strt == deptCity) break;
      cur = cur->next;
   }

   if( cur == NULL){
      cout<< "No possible way."<< endl;
      return;
   }
   else{
      prev = deptCity;
      while( cur != NULL){
         if( cur->strt == deptCity && cur->fnl == destCity){
            allPaths[row].insert( 1, destCity);
            allPaths[row].insert( 1, deptCity);
            row++;
         }
         if( cur->strt == prev && !cur->visited)
            break;

         cur = cur->next;
      }

      if( cur != NULL){
         top = cur->fnl;
      }
      else{
         cout<< "No possible way."<< endl;
         return;
      }
   }

   cur->visited = true;
   path.push( prev);
   path.push( top);

   while( !path.isEmpty()){
      edge* tempTop = head;
      while( tempTop != NULL){
         if( tempTop->strt == top && !tempTop->visited)   break;

         tempTop = tempTop->next;
      }
      if( tempTop == NULL){
         path.pop();
      }
      else{
         tempTop->visited = true;
         prev = top;
         top = tempTop->fnl;
         cur = tempTop;
         path.push( top);
      }

      string d1;
      path.getTop( d1);
      if( d1 == destCity){
         Stack tStack;
         string a, b;

         path.pop( a);
         allPaths[row].insert( 1, a);
         if( cur != NULL)
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
   int row = 0;
   string top, prev;
   Stack path;
   ListF allPaths[length];

   // mark all elements false
   while( cur != NULL){
      cur->visited = false;
      cur = cur->next;
   }

   cur = head;
   // find the deptCity in the linked list
   while( cur != NULL){
      if( cur->strt == deptCity) break;
      cur = cur->next;
   }

   if( cur == NULL){
      cout<< "No possible way."<< endl;
      return;
   }
   else{
      prev = deptCity;
      while( cur != NULL){
         if( cur->strt == deptCity && cur->fnl == destCity){
            allPaths[row].insert( 1, destCity);
            allPaths[row].insert( 1, deptCity);
            row++;
         }
         if( cur->strt == prev && !cur->visited)
            break;

         cur = cur->next;
      }

      if( cur != NULL){
         top = cur->fnl;
      }
      else{
         cout<< "No possible way."<< endl;
         return;
      }
   }

   cur->visited = true;
   path.push( prev);
   path.push( top);

   while( !path.isEmpty()){
      edge* tempTop = head;
      while( tempTop != NULL){
         if( tempTop->strt == top && !tempTop->visited)   break;

         tempTop = tempTop->next;
      }
      if( tempTop == NULL){
         path.pop();
      }
      else{
         tempTop->visited = true;
         prev = top;
         top = tempTop->fnl;
         cur = tempTop;
         path.push( top);
      }

      string d1;
      path.getTop( d1);
      if( d1 == destCity){
         Stack tStack;
         string a, b;

         path.pop( a);
         allPaths[row].insert( 1, a);
         if( cur != NULL)
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
            cout<< print<< "."<< " and it costs "<< totalPrice<< " TL"
                                                 <<endl;
      }
   }
   else{
      cout<< "No paths found from "<< deptCity<< " to "<< destCity<< endl;
   }
}
void FlightMap::runFlightRequests( const string requestFile ) const{
   string origin, dest;
   ifstream inputFile;

   //Open the stream for the input file
   inputFile.open( requestFile.c_str(), ios_base::in);

   // count the cities form the city file
   while ( inputFile.eof() == false){
      getline( inputFile, origin, ',');
      getline( inputFile, dest, '\n');
      findLeastCostFlight( origin, dest);
   }
   inputFile.close();
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

