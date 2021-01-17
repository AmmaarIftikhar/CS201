#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <iostream>
#include <string>
#include "Book.h"
#include "ListP.h"
#include "ListB.h"
#include "Student.h"

class LibrarySystem {
public:
   LibrarySystem();
   ~LibrarySystem();
   void addBook(const int bookId, const string bookName, const int bookYear);
   void deleteBook(const int bookId);
   void addStudent(const int studentId, const string studentName);
   void deleteStudent(const int studentId);
   void checkoutBook(const int bookId, const int studentId);
   void returnBook(const int bookId);
   void showAllBooks() const;
   void showBook(const int bookId) const;
   void showStudent(const int studentId) const;

private:
   ListP* students;
   ListB* available;
   ListB* allBooks;

   bool checkAvailabilitity( const int, int&) const;
};

#endif // LIBRARYSYSTEM_H

