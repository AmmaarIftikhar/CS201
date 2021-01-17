/*Ammaar Iftikhar
   21901257
   Section 1*/
#include<iostream>
#include<string>
#include "SimpleStudent.h"
#include "SimpleLibrarySystem.h"
#include "ListP.h"
using namespace std;

LibrarySystem::LibrarySystem() {
    students = new ListP;
}

LibrarySystem::~LibrarySystem() {
    delete students;
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
   if( studentId < 1) {
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
         break;
      }
      else if( studentId > temp.getID() || i == students->getLength()) {
         cout<< "Student "<< studentId<< " does not exist.";
         return;
      }
   }

   // remove the student
   if( index != -1){
      students->remove(index);
   }
   else
      cout<< "Student "<< studentId<< " does not exist.";
}

void LibrarySystem::showStudent( const int studentId) const{
    // check for valid id
    if (studentId <= 0) {
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
            cout << "Student "<< studentId<< " not in records." << endl;
            return;
        }
    }
   if( index != -1){
      Student temp;
      students->retrieve(index, temp);
      // display the student
      cout << "Name: " << temp.getName()
            << "ID:    " << temp.getID() << endl;
   }
   else{
      cout << "Student"<< studentId<< " not in records." << endl;
   }
}
