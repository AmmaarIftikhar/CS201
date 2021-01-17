/*Ammaar Iftikhar
  21901257
  Section 1*/

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;

class Book{
public:
   Book( int = 0, int = 0, string = "");
   Book( const Book&);
   void operator=( const Book&);
   void setYear( int);
   void setId( int);
   void setTitle( string);
   int  getYear() const;
   int getId() const;
   string getTitle() const;

private:
   int id;
   int year;
   string title;
};
#endif // BOOK_H

