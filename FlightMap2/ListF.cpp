/*Ammaar Iftikhar
   21901257
   Section 1*/
#include <iostream>
#include <string>
#include "ListF.h"
using namespace std;

ListF::ListF()
	: size(0), head(NULL) {}


ListF::~ListF() {
	ListNode* cur = head;
	ListNode* prev;
	while( cur != NULL){
      prev = cur;
      cur = prev->next;
      delete prev;
	}
}


bool ListF::isEmpty()  const{
	return size == 0;
}


int ListF::getLength() const{
	return size;
}


ListF::ListNode* ListF::find(int index) const{

	ListNode* cur = head;
	for (int i = 1; i < index; i++)
		cur = cur->next;

	return cur;
}


void ListF::insert( int index, string element) {
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
void ListF::retrieve( int index, string& element) const{
	if (index < 1 || index > size)   return;

	element = find(index)->item;
}


void ListF::remove(int index) {
	if (index < 1 || index > size)   return;

	if (index == 1) {
		ListNode* cur;
		cur = head;
		head = head->next;
		cur->next = NULL;
		delete cur;
	}
	else {
		ListNode* cur, * prev;
		prev = find(index - 1);
		cur = prev->next;
		prev->next = cur->next;

		cur->next = NULL;
		delete cur;
	}
	size--;
}

