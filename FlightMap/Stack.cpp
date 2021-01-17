/* Ammaar Iftikhar
   21901257
   Section 1*/

#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

Stack::Stack(){
   topPtr = NULL;
}


Stack::Stack( Stack& s){
   if( s.topPtr == NULL){
      return;
      topPtr = NULL;
   }

   StackNode* oldCur = s.topPtr->next;
   StackNode* cur = new StackNode;
   cur->item = s.topPtr->item;
   topPtr = cur;

   while( oldCur != NULL){
      cur->next = new StackNode;
      cur->next->item = oldCur->item;
      oldCur = oldCur->next;
      cur = cur->next;
   }

   cur->next = NULL;
}


Stack::~Stack(){

//   while( topPtr != NULL){
//      StackNode* node = topPtr;
//      topPtr = topPtr->next;
//      node->next = NULL;
//      delete node;
//   }
}


bool Stack::isEmpty() const{
   return topPtr == NULL;
}


bool Stack::push( string& s){
   StackNode* newNode = new StackNode;
   newNode->item = s;
   newNode->next = topPtr;
   topPtr = newNode;

   return true;
}


bool Stack::pop(){
   if( isEmpty())
      return false;

   StackNode* cur = topPtr;
   topPtr = topPtr->next;
   cur->next = NULL;
//   delete cur;
   return true;
}


bool Stack::pop( string& s){
   if( isEmpty()) return false;
   s = topPtr->item;
   return pop();
}


bool Stack::getTop( string& s) const{
   if( isEmpty()) return false;

   s = topPtr->item;
   return true;
}
