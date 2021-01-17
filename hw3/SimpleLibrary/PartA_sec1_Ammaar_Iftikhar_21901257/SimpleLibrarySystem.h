/*Ammaar Iftikhar
   21901257
   Section 1*/
#ifndef SIMPLELIBRARYSYSTEM_H
#define SIMPLELIBRARYSYSTEM_H
#include <iostream>
#include <string>
#include "ListP.h"
#include "SimpleStudent.h"
using namespace std;

class LibrarySystem {
public:
    LibrarySystem();
    ~LibrarySystem();
    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void showStudent(const int studentId) const;

private:
    ListP* students;
};
#endif // SIMPLELIBRARYSYSTEM_H

