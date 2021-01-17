/* Ammaar Iftikhar
   21901257
   Section 1*/

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;

class Stack{
public:
   Stack();
   Stack( Stack&);
   ~Stack();
   bool isEmpty() const;
   bool push( string&);
   bool pop();
   bool pop( string&);
   bool getTop( string& ) const;

private:
   struct StackNode{
      StackNode* next;
      string  item;
   };

   StackNode* topPtr;
};
#endif // STACK_H
