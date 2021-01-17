#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Book.h"
#include "ListB.h"
using namespace std;

class Student {

public:
	Student(const string name ="", const int id = 0);
	Student(const Student&);
	~Student();
	string getName() const;
	int getID() const;
	void setName(const string);
	void setID(const int);
	void operator=(Student&);
	// functions related to books
	void addBook( const Book);
	bool returnBook( const int, Book&);
	ListB* returnAllBooks();
	bool checkBook( int);
   void showAllBooks();

private:
	int id;
	string name;
   ListB* borrowed;
};
#endif // SIMPLESTUDENT_H
