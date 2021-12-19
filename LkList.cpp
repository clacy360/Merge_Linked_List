///
// Author: Cami Lacy
//
// Assignment: OP1 Merge for Linked List
//
// Description: This file contains the function definitions to the
// LkList class' function declarations stated in the header file.
// We can call the public functions in main to use to 
// insert into lists, merge lists, check size, and several others. 
// It does not take any input, nor does it output to the screen. 
//
///

#include "LkList.h"
#include <iostream>

using namespace std;


// DELETE THIS LATER DUUUDE
void LkList::removeLast()
{
	// set it at tail
	it = tail;

	// set tail to prev node
	tail = it->prev;

	// delete it at the last node
	delete it;

	// set tail right to nullptr
	tail->next = nullptr;

}


void LkList::merge(LkList& src) {

	// Set it to head
	it = head;
	src.it = src.head;

	// if list1 is empty
	if (head == nullptr)
	{

		// just set this to the src
		head = src.head;
		tail = src.tail;

		// Set sizes equal to each other
		count = src.count;

		// now reset src size
		src.count = 0;

		// set src to empty
		src.head = nullptr;
		src.tail = nullptr;


	}

	// if src is empty
	else if (src.head == nullptr)
	{
		// Do nothing
	}

	// Else if all src nodes are smaller
	else if (src.tail->data < head->data)
	{

		// attach list1 head to src tail
		head->prev = src.tail;

		// attach src to list1 head
		src.tail->next = head;

		// set new head
		head = src.head;

		// Set new count
		count += src.count;

		// reset src size
		src.count = 0;

		// set src to empty
		src.head = nullptr;
		src.tail = nullptr;


	}

	// Else if all src nodes are larger
	else if (src.head->data > tail->data)
	{

		// attach list1 tail to src head
		tail->next = src.head;

		// attach the src head to the list1 tail
		src.head->prev = tail;

		// Set new tail
		tail = src.tail;

		// Set new count
		count += src.count;

		// reset src size
		src.count = 0;

		// set src to empty
		src.head = nullptr;
		src.tail = nullptr;

	}
	else // source overlaps destination or source is within destination
	{
		// if src tail is greater than list1
		if (src.tail->data > tail->data)
		{
			// attach the src end 
			// set src it to tail 
			src.it = src.tail;

			// go back while greater than tail
			while (src.it->data > tail->data)
			{
				src.it = src.it->prev;
			}

			// attach list1 tail right to src
			tail->next = src.it->next;

			// attach the src left to list1 tail
			src.it->next->prev = tail;

			// update tail
			tail = src.tail;

			// update src tail
			src.tail = src.it;
			
			// point to nullptr as src tail
			src.it->next = nullptr;

		}
		if (src.head->data < head->data)
		{

			// attach src front 
			// set src it to head
			src.it = src.head;

			// move it while lesser than list1 head
			while (src.it->data < head->data)
			{
				src.it = src.it->next;
			}
			 
			// attach list1 head left to src
			head->prev = src.it->prev;

			// attach src right to listq
			src.it->prev->next = head;

			// update head
			head = src.head;

			// update src head
			src.head = src.it;

		}

		// set iterators
		it = head->next;
		src.it = src.head;

		while (true)
		{
			// move src it while less than list1
			while (src.it->data < it->data)
			{
				if (src.it->next != nullptr)
				{
					// Move iterator
					src.it = src.it->next;
				}
				else
				{
					break;
				}

			}

			// attach list1 right to src
			it->prev->next = src.head;

			// attach src head left to list1
			src.head->prev = it->prev;

			// attach list1 left to src
			it->prev = src.it->prev;

			// attach src right to list1
			src.it->prev->next = it;


			// set new src head
			src.head = src.it;

			// move it
			it = it->next;

			// if we have reached end of src list
			if (src.it->next == nullptr)
			{
				// Set new count
				count += src.count;

				// reset src size
				src.count = 0;

				// set src to empty
				src.head = nullptr;
				src.tail = nullptr;
				break;
			}

		} // end while

	} // end else



}  // end of merge function


LkList::LkList() {
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}

//LkList::~LkList(){}                      
//LkList::LkList(const LkList& other){}
//LkList& LkList::operator=(const LkList& rhs){}

int LkList::size() {
	return count;
}

bool LkList::insert(int num) {
	if (count == 0) {                      // empty list
		head = tail = new Node(num);
	}
	else {                                   // >1 count, then add back
		Node* temp = new Node(num);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	count++;
	return true;
}

void LkList::insert(const initializer_list<int>& il) {
	for (int ele : il) {
		insert(ele);
	}
}


void LkList::clear() {
	if (count == 0)
		return;

	while (tail != head) {
		tail = tail->prev;
		delete tail->next;
	}
	delete head;
	head = tail = nullptr;
	count = 0;
}

void LkList::resetIterator() {
	it = head;
}

bool LkList::hasMore() {
	return (it != nullptr);
}

int LkList::next() {
	int num = it->data;
	it = it->next;
	return num;
}

ostream& operator << (ostream & outStr, LkList & lst) {
	lst.resetIterator();
	while (lst.hasMore())
		outStr << lst.next() << "  ";
	return outStr;
}