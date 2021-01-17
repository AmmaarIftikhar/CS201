/*Ammaar Iftikhar
  21901257
  Section 1*/

#include "ListB.h"
#include "Book.h"
#include <iostream>

ListB::ListB(){
   size = 0;
   head= NULL;
}

ListB::~ListB() {
	ListNode* cur = head;
	ListNode* prev;
	while( cur != NULL){
      prev = cur;
      cur = prev->next;
      delete prev;
      prev = NULL;
	}
}

bool ListB::isEmpty()  const{
	return size == 0;
}

int ListB::getLength() const{
	return size;
}

ListB::ListNode* ListB::find(int index) const{

	ListNode* cur = head;
	for (int i = 1; i < index; i++)
		cur = cur->next;

	return cur;
}

void ListB::insert( int index, ItemType element) {
	if (index < 1 || index >(size + 1))
		return;

	if (index == 1) {
		ListNode *newNode = new ListNode;
		newNode->item = element;
		newNode->next = head;
		head = newNode;
	}
	else {
		ListNode* newNode = new ListNode;
		newNode->item = element;
		ListNode* cur = find(index - 1);
		newNode->next = cur->next;
		cur->next = newNode;
	}
	size++;
}

void ListB::retrieve( int index, ItemType& element) const{
	if (index < 1 || index > size)   return;

	element = find(index)->item;
}

void ListB::remove(int index) {
	if (index < 1 || index > size)   return;

	if (index == 1) {
		ListNode* cur;
		cur = head;
		head = head->next;
		cur->next = NULL;
		delete cur;
		cur = NULL;
	}
	else {
		ListNode* cur, * prev;
		prev = find(index - 1);
		cur = prev->next;
		prev->next = cur->next;
		cur->next = NULL;
		delete cur;
		cur = NULL;
	}
	size--;
}


