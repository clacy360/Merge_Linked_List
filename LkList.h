///
// Author: Cami Lacy
//
// Assignment: OP1 Merge for Linked List
//
// Description: This header file contains the node class and 
// LkList class. This file has the node classes' constructor
// and function definition here. The LkList class is used to
// insert into lists, merge lists, check size, and several others. 
// It does not take any input, nor does it output to the screen. 
//
///


#ifndef LKLIST_H
#define LKLIST_H
#include <string>

using namespace std;

class LkList {

	class Node {
		public:
		Node() {
			next = prev = nullptr;
		}
		Node(int num) {
			data = num; next = prev = nullptr;
		}

		int data;
		Node *next;
		Node *prev;
	};

	public:
	LkList();
	        //virtual ~LkList();
	        //LkList(const LkList& other);
	        //LkList& operator=(const LkList& other);

	bool insert(int num);
	void insert(const initializer_list<int>& il);

	void merge(LkList & src);

	void resetIterator();
	bool hasMore();
	int next();

	int size();
	void clear();

	void removeLast(); // DELETE THIS LATER DUDE

	private:
	Node *head, *tail, *it;
	int count;
};

ostream& operator << (ostream & outStr, LkList& lst);

#endif  LKLIST_H
