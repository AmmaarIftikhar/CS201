/*Ammaar Iftikhar
   21901257
   Section 1*/

#ifndef SIMPLESTUDENT_H
#define SIMPLESTUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student {

public:
	Student(const string name ="", const int id = 0);
	Student(const Student&);
	string getName() const;
	int getID() const;
	void setName(const string);
	void setID(const int);
	void operator=(Student&);

private:
	int id;
	string name;

};
#endif // SIMPLESTUDENT_H

