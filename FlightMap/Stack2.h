/* Ammaar Iftikhar
   21901257
   Section 1*/
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
typedef string StackType;

class Stack{
public:
   Stack();
   Stack( Stack&);
   ~Stack();
   bool isEmpty() const;
   bool push( StackType&);
   bool pop();
   bool pop( StackType&);
   bool getTop( StackType& ) const;

private:
   struct StackNode{
      StackNode* next;
      StackType  item;
   };

   StackNode* topPtr;
};
#endif // STACK_H

