/*Ammaar Iftikhar
  21901257
  Section 1*/

#ifndef LISTB_H
#define LISTB_H
#include "Book.h"
typedef Book ItemType;

class ListB {
public:
	ListB();
	~ListB();
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

