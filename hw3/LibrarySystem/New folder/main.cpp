#include<iostream>
#include<string>
#include "Student.h"
#include "Book.h"
#include "LibrarySystem.h"

using namespace std;
int main() {
LibrarySystem LS;
LS.addBook(1000, "Machine Learning", 1997);
LS.addBook(1200, "Data Mining", 1991);
LS.addBook(1300, "Problem S. with C++", 1991);
LS.addBook(1400, "C++ How to Program", 2005);
LS.addBook(1200, "Data Mining", 1991);
LS.deleteBook(1300);
LS.deleteBook(2000);
LS.addBook(1500, "Pattern Recognition", 2000);
cout << endl;
LS.addStudent(21000000, "Selim Aksoy");
LS.addStudent(21000011, "Ercument Cicek");
LS.addStudent(21000011, "Aydamir Mirzayev");
LS.addStudent(21000020, "Mert Duman");
LS.addStudent(21000001, "Han Solo");
LS.addStudent(21000005, "Jack Ryan");
LS.deleteStudent(21000011);
LS.deleteStudent(21000050);
cout << endl;
LS.checkoutBook(1200, 21000000);
LS.checkoutBook(1400, 21000020);
LS.checkoutBook(2050, 21000011);
LS.checkoutBook(1000, 21000444);
LS.checkoutBook(1500, 21000000);
LS.checkoutBook(1400, 21000001);
cout << endl;
LS.showStudent(21000000);
cout << endl;
LS.showStudent(21000005);
cout << endl;
LS.showStudent(21000011);
cout << endl;
LS.showBook(1000);
LS.showBook(1200);
cout << endl;
LS.showAllBooks();
cout << endl;
LS.returnBook(1200);
LS.returnBook(1000);
cout << endl;
LS.checkoutBook(1200, 21000020);
LS.checkoutBook(1000, 21000000);
cout << endl;
LS.showAllBooks();
cout << endl;
LS.deleteStudent(21000020);
cout << endl;
LS.deleteBook(1000);
cout << endl;
LS.showStudent(21000000);
cout << endl;
LS.showAllBooks();
return 0;
}
