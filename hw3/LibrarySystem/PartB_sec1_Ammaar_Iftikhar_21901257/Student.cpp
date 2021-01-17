/*Ammaar Iftikhar
  21901257
  Section 1*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
#include "Book.h"
#include "ListB.h"
using namespace std;

	Student::Student(const string name, const int id) {
		this->name = name;
		this->id = id;
		borrowed = new ListB;
	}

	Student::Student(const Student& s) {
		this->name = s.name;
		this->id = s.id;
		this->borrowed = s.borrowed;
	}

   Student::~Student(){
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

      int index{ 1};

      while( index <= borrowed->getLength()){
         Book book;
         borrowed->retrieve( index, book);
         if( b.getId() < book.getId()) break;
         index++;
      }

      borrowed->insert( index, b);
   }

   bool Student::returnBook(const int bookId, Book& b){
      for( int i = 1; i <= borrowed->getLength(); i++){
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
      ListB* temp = new ListB;
      for( int i = 1; i < borrowed->getLength(); i++){
         Book book;
         borrowed->retrieve( i, book);

         temp->insert( i, book);
      }

      return temp;
   }



   void Student::showAllBooks(){
      if( borrowed->getLength() > 0){
         cout<< "Books with "<< name<< " borrowed are:"<< endl;
         for( int i = 1; i <= borrowed->getLength(); i++){
            Book temp;
            borrowed->retrieve( i, temp);
            cout<< setw(20)<< temp.getTitle();
            cout<< setw(20)<< temp.getId();
            cout<< setw(20)<<temp.getYear()<< endl;
         }
      }
   }
