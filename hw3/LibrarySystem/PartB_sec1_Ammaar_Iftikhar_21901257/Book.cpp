/*Ammaar Iftikhar
  21901257
  Section 1*/

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book::Book( int id, int year, string title){
   this->id     = id;
   this->year   = year;
   this->title = title;
}

Book::Book( const Book& b){
   id    = b.id;
   year  = b.year;
   title = b.title;
}

void Book::operator=( const Book& b){
   id    = b.id;
   year  = b.year;
   title = b.title;
}

void Book::setId( int id){
   this->id = id;
}

void Book::setYear( int year){
   this->year = year;
}

void Book::setTitle( string title){
   this->title = title;
}

int Book::getId() const{
   return id;
}

int Book::getYear() const{
   return year;
}

string Book::getTitle() const{
   return title;
}

