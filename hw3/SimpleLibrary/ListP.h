/*Ammaar Iftikhar
   21901257
   Section 1*/

#ifndef LISTP_H
#define LISTP_H
#include "SimpleStudent.h"
typedef Student ItemType;

class ListP {
public:
	ListP();
	// add a copy constuctor
	~ListP();
	bool isEmpty() const;
	int getLength() const;
	void retrieve( int, ItemType&) const;
	void remove( int);
	void insert(int, ItemType);

private:
	struct ListNode {
		ListNode* next;
		ItemType item;
	};
	ListNode* find(int) const;

	// data members
	int size;
	ListNode* head;
};


#endif
