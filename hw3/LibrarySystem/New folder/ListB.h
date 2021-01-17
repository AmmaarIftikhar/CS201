#ifndef LISTB_H
#define LISTB_H
#include "Book.h"
typedef Book ItemType;

class ListB {
public:
	ListB();
	// add a copy constuctor
	~ListB();
	bool isEmpty() const;
	int getLength() const;
	void retrieve( int, ItemType&);
	void remove( int);
	void insert(int, ItemType);

private:
	struct ListNode {
		ListNode* next;
		ItemType item;
	};

	ListNode* find(int);

	// data members
	int size;
	ListNode* head;
};


#endif

