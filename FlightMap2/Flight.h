/* Ammaar Iftikhar
   21901257
   Section 1*/

#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>
using namespace std;

class Flight{
public:
   Flight( const string = "", const string = "", const int = 0, const int = 0);
   Flight( const Flight&);
   void setId( const int);
   void setPrice( const int);
   void setDestination( const string);
   void setOrigin( const string);
   int getId() const;
   int getPrice() const;
   string getOrigin() const;
   string getDestination() const;
   void        printInfo() const;

private:
   int price;
   int id;
   string destination;
   string origin;
};

#endif // FLIGHT_H

