#ifndef LISTP_H
#define LISTP_H
#include "Student.h"
//typedef Student ItemType;

class ListP {
public:
	ListP();
	// add a copy constuctor
	~ListP();
	bool isEmpty() const;
	int getLength() const;
	void retrieve( int, Student&);
	void remove( int);
	void insert(int, Student);

private:
	struct ListNode{
		ListNode* next;
		Student item;
	};

	ListNode* find(int);
	// data members
	int size;
	ListNode* head;
};


#endif

