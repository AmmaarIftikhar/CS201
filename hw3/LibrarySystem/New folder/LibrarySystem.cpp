#include<iostream>
#include<string>
#include "Student.h"
#include "Book.h"
#include "LibrarySystem.h"
#include "ListP.h"
#include "ListB.h"
using namespace std;

LibrarySystem::LibrarySystem() {
    students = new ListP;
    allBooks = new ListB;
    available = new ListB;
}

LibrarySystem::~LibrarySystem() {
    delete students;
    delete available;
    delete allBooks;
}

void LibrarySystem::addStudent(const int studentId, const string studentName) {
    if( studentId < 1){
      cout<< "Invalid student Id."<< endl;
      return;
    }
    // check if the student with the same id already exists
    // if not then add the student
    if( students->getLength() > 1) {
        for( int i = 1; i <= students->getLength(); i++){
            Student temp;
            students->retrieve(i, temp);

            if (temp.getID() == studentId) {
                cout << "Student "<< studentId<< " already exists."<< endl;
                return;
            }
            else if ( studentId < temp.getID()) {
                Student a(studentName, studentId);
                students->insert(i, a);
                break;
            }
            else if (i == students->getLength()) {
                Student a(studentName, studentId);
                students->insert(i + 1, a);
                break;
            }
        }
    }
    else {
        Student a(studentName, studentId);
        students->insert(1, a);
    }

    cout<< "Student "<< studentId<< " has been added."<< endl;
}

void LibrarySystem::deleteStudent(const int studentId) {
   // check for valid id
   if( studentId <= 0) {
      cout << "Invalid id input." << endl;
      return;
   }

   int index{ -1 };

   // find the index of the student with id = student id
   for( int i = 1; i <= students->getLength(); i++) {
      Student temp;
      students->retrieve( i, temp);

      if( temp.getID() == studentId){
         cout<<"Student "<< temp.getID()<< " has been deleted from the memory."<<endl;

         index = i;
         // return all the books back
         ListB* temp2 = temp.returnAllBooks();
         for( int k = 1; k <= temp2->getLength(); k++){
            Book copyBook;
            temp2->retrieve( k, copyBook);

            for( int j = 1; j <= available->getLength(); j++){
               Book avail;
               available->retrieve( j, avail);
               if( copyBook.getId() < avail.getId())
                  available->insert( j, copyBook);
            }
         }

         delete temp2;
         break;
      }
      else if( temp.getID() > studentId && i == students->getLength()) {
         cout<< "Student "<< studentId<< " does not exist.";
         return;
      }
   }

   // remove the student
   if( index != -1){
      students->remove(index);
   }
}

void LibrarySystem::showStudent( const int studentId) const{

   // check for valid id
   if (studentId < 1) {
      cout << "Invalid id input." << endl;
      return;
   }

   int index{ -1 };

   // find the index of the student with id = student id
   for (int i = 1; i <= students->getLength(); i++) {
      Student temp;
      students->retrieve(i, temp);

      if (temp.getID() == studentId) {
         index = i;
         break;
      }
      else if (temp.getID() > studentId && i == students->getLength()) {
         cout << "Student "<< studentId<< " does not exist." << endl;
         return;
      }
   }

   // display the student
   if( index != -1){
      Student temp;
      students->retrieve(index, temp);
      cout<< "Student Name: " << temp.getName()
         << "  Student ID: " << temp.getID()<< endl;
      cout<< "The book borrowed are:"<< endl;
      temp.showAllBooks();
   }
}

void LibrarySystem::addBook(const int bookId, const string bookName, const int year) {
   if( bookId <= 0) return;

   // check if the student with the same id already exists
   // if not then add the student
   if( allBooks->getLength() > 1) {
      for( int i = 1; i <= allBooks->getLength(); i++) {
         Book temp;
         allBooks->retrieve(i, temp);

         if( temp.getId() == bookId){
               cout << "A Book with Id = "<< bookId<< " already exists." << endl;
               return;
         }
         else if( bookId < temp.getId()){
            Book a( bookId, year, bookName);
            allBooks->insert(i, a);

            if( available->getLength() == 0)
               available->insert( 1, a);
            else{
               // adding to the available book list
               for ( int j = 1; j <= available->getLength(); j++){
                  Book temp2;
                  available->retrieve( j, temp2);

                  if(temp2.getId() < bookId) {
                     available->insert( j, a);
                  }
                  else if( j == available->getLength()){
                     available->insert( j + 1, a);
                  }
               }
            }
            break;
         }
         else if (i == allBooks->getLength()) {
            Book a(bookId, year, bookName);
            available->insert( available->getLength() + 1, a);
            allBooks->insert(i, a);
            break;
         }
      }
   }
   else{
      Book a(bookId, year, bookName);
      allBooks->insert(1, a);
      available->insert(1, a);
   }
   cout<< "Book "<< bookId<<" has been added."<< endl;
}

void LibrarySystem::deleteBook( const int bookId){
   if( bookId < 1) return;

   // check if the student with the same id already exists
   // if then delete the book
   if( allBooks->getLength() > 0){
      for( int i = 1; i <= allBooks->getLength(); i++){
         Book temp;
         allBooks->retrieve(i, temp);

         if( temp.getId() == bookId) {
            int index;
            bool availStat = checkAvailabilitity( bookId, index);

            if( !availStat){
               // find the student borrower of the book.
               for( int k = 1; k < students->getLength(); k++){
                  Student alpha;

                  students->retrieve( k, alpha);
                  if( alpha.returnBook( bookId, temp)){

                     break;
                  }
               }
            }
            else{
               cout<< "The Book has not been checked out."<< endl;
               available->remove(index);
            }
            allBooks->remove(i);
            cout << "Book "<< bookId<< " has been deleted." << endl;
            return;
         }
      }
   }
   cout<< "Book "<< bookId<< " does not exist.\n\n";
}

void LibrarySystem::checkoutBook( const int bookId, const int studentId){
   if( studentId < 1 || bookId < 1){
         cout<< "Invalid input!;"<< endl;
      return;
   }

   // search for the book
   for( int i = 1; i <= available->getLength(); i++)
   {
      Book temp;
      available->retrieve( i, temp);

      if( temp.getId() == bookId){
         // search for the student
         for( int j = 1; j <= students->getLength(); j++){
            Student t;
            students->retrieve( j, t);

            if( t.getID() == studentId){
               // add the book to the student's list
               // remove the book from the available list
               t.addBook( temp);
               available->remove(i);
               return;
            }
         }
      }
   }
}

void LibrarySystem::returnBook(const int bookId){
   if( bookId <= 0)   return;

   for( int i = 1; i <= allBooks->getLength(); i++){
      Book temp;
      allBooks->retrieve( i, temp);
      if( temp.getId() == bookId){
         for( int j = 1; j <= allBooks->getLength(); j++){
            Book temp2;
            available->retrieve( j, temp2);
            if( temp2.getId() == bookId){
               cout<< "The book has not been borrowed."<< endl;
               return;
            }
         }

         Book returned;
         for( int j = 1; j <= students->getLength(); j++){
            Student temp2;
            students->retrieve( j, temp2);
            Book temp3;
            if( temp2.returnBook( bookId, temp3)){
               cout<< "Book with title = "<< temp3.getTitle()<< " has been returned."<< endl;
               cout<< "Checkpoint 1"<< endl;
               for( int k = 1; k <= available->getLength(); k++){
                  cout<< "Checkpoint 3"<< endl;
                  Book temp2;
                  available->retrieve( k, temp2);

                  if(temp2.getId() < bookId) {
                     available->insert( k, temp3);
                     return;
                  }
                  else if( j == available->getLength()){
                     available->insert( k + 1, temp3);
                     return;
                  }
               }
               return;
            }
         }
      }
   }
}

void LibrarySystem::showBook( const int bookId) const{
   for( int i = 1; i <= allBooks->getLength(); i++){
      Book temp;
      allBooks->retrieve( i, temp);
      if( temp.getId() == bookId){
         cout<< temp.getTitle()<< " "<< temp.getId()<< " "<<temp.getYear();
      }
   }
}

void LibrarySystem::showAllBooks() const{
   for( int i = 1; i <= allBooks->getLength(); i++){
      Book temp;
      allBooks->retrieve( i, temp);
      cout<< temp.getTitle()<< "  "<< temp.getId()<< "  "<<temp.getYear()<< endl;
   }
}

bool LibrarySystem::checkAvailabilitity( const int bookId, int& ind) const{
   for( int i = 1; i <= available->getLength(); i++){
      Book temp2;
      available->retrieve( i, temp2);

      if( temp2.getId() == bookId){
         ind = i;
         return true;
      }
   }
   ind = -1;
   return false;
}
