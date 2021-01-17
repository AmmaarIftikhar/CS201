/*Ammaar Iftikhar
   21901257
   Section 1*/

#ifndef ListF_H
#define ListF_H
#include <string>
using namespace std;

class ListF{
public:
	ListF();
	// add a copy constuctor
	~ListF();
	bool isEmpty() const;
	int getLength() const;
	void retrieve( int, string&) const;
	void remove( int);
	void insert(int, string);

private:
	struct ListNode {
		ListNode* next;
		string item;
	};
	ListNode* find(int) const;

	// data members
	int size;
	ListNode* head;
};


#endif

