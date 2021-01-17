#include <iostream>
#include <string>
#include "Student.h"
#include "Book.h"
#include "ListB.h"
using namespace std;

	Student::Student(const string name, const int id) {
		this->name = name;
		this->id = id;
		this->borrowed = new ListB;
	}

	Student::Student(const Student& s) {
		this->name = s.name;
		this->id = s.id;
		this->borrowed = s.borrowed;
	}

	Student::~Student(){
	   delete borrowed;
	}

	string Student::getName() const {
		return this->name;
	}
	int Student::getID() const {
		return this->id;
	}
	void Student::setName(const string n) {
		name = n;
	}
	void Student::setID(const int ID) {
		id = ID;
	}

	void Student::operator=(Student& a) {
		id = a.id;
		name = a.name;
		borrowed = a.borrowed;
	}


   void Student::addBook( const Book b){

      cout<< "Book "<< b.getId()<<" has been checked out by student "<< id<< endl;
      if( borrowed->getLength() < 1){
         borrowed->insert(1, b);
         return;
      }
      else{
         for( int i = 1; i <= borrowed->getLength(); i++){
            Book temp;
            borrowed->retrieve( i, temp);

            if( b.getId() < temp.getId()){
               borrowed->insert( i, b);
               return;
            }
            else if( i == borrowed->getLength()){
               borrowed->insert( borrowed->getLength() + 1, b);
               return;
            }
         }
      }
   }

   bool Student::returnBook(const int bookId, Book& b){
      for( int i = 1; i < borrowed->getLength(); i++){
         Book temp;
         borrowed->retrieve( i, temp);
         if( bookId == temp.getId()){
            b = temp;
            borrowed->remove( i);
            return true;
         }
      }
      return false;
   }

   ListB* Student::returnAllBooks(){
      ListB* temp = borrowed;
      borrowed = new ListB();
      return temp;
   }

   bool Student::checkBook( int bookId){
      for( int i = 1; i <= borrowed->getLength(); i++){
         Book temp;
         borrowed->retrieve( i, temp);

         if( temp.getId() == bookId){
            return true;
         }
      }
      return false;
   }

   void Student::showAllBooks(){
      for( int i = 1; i <= borrowed->getLength(); i++){
         Book t;
         borrowed->retrieve( i, t);
         cout<< t.getId()<< "  "<< t.getTitle()<< "  "<< t.getYear()<< endl;
      }
   }
