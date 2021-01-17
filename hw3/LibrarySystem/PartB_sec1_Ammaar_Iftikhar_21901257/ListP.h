/*Ammaar Iftikhar
  21901257
  Section 1*/

#ifndef LISTP_H
#define LISTP_H
#include "Student.h"

class ListP {
public:
	ListP();
	~ListP();
	bool isEmpty() const;
	int getLength() const;
	void retrieve( int, Student&) const;
	void remove( int);
	void insert(int, Student);

private:
	struct ListNode{
		ListNode* next;
		Student item;
	};

	ListNode* find(int) const;
	// data members
	int size;
	ListNode* head;
};


#endif

