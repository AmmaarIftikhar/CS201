/*Ammaar Iftikhar
  Section1
  21901257*/

#include "Aircraft.h"
#include <iostream>
using namespace std;
Aircraft::Aircraft( const int row,const int column){
   setRow( row);
   setColumn( column);
}

/* this method returns the value
    of the number of rows in the aircraft*/
int Aircraft::getRow() const{
   return row;
}

/* this method returns the value
    of the number of cloumns in the aircraft*/
int Aircraft::getColumn() const{
   return column;
}

/* this method initialises the row
     data member*/
void Aircraft::setRow( const int row){
//   if ( row > 0)
      this->row = row;     // after dereferencing this we initialise the column of the class
/*   else{
      this->row = 0;
      cout << "The row value is invalid."<< endl;
  }*/
}

/* this method initialises the column
     data member*/
void Aircraft::setColumn(const int column){
 // if (column > 0)
    this->column = column;    // after dereferencing this we initialize the column of the class
  /*else{
     this->column = 0;
     cout<< "The value entered for the column is invalid."<<endl;
  }*/
}

