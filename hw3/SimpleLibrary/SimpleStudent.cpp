/*Ammaar Iftikhar
   21901257
   Section 1*/

#include <iostream>
#include <string>
#include "SimpleStudent.h"
using namespace std;

	Student::Student(const string name, const int id) {
		this->name = name;
		this->id = id;
	}

	Student::Student(const Student& s) {
		this->name = s.name;
		this->id = s.id;
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
	}
