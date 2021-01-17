/*Ammaar Iftikhar
   21901257
   Section 1*/

#ifndef ListP_H
#define ListP_H
#include "Flight.h"
typedef Flight ItemType;

class ListP{
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
