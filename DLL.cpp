
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DLL::DLL(){  // constructor - initializes an empty list
	last = NULL;
	first = NULL;
	size = 0;
}
DLL::DLL(int x){  // constructor, initializes a list with one new node with data x
	DNode *n = new DNode (x);
	first = n;
	last = n;
	size=1;
}
/***************************************************************************************************/
/*Part 1																																		*/
/***************************************************************************************************/
/* write push, pop, addAtFront */
void DLL::push(int x) {
	if (last == NULL) {
		DNode *n = new DNode(x);
		first = n;
		last = n;
	} else {
		DNode *n = new DNode(x);
		last->next = n;
		n->prev = last;
		last = n;
	}
	size++;
}
int DLL::pop() {
	int listData;
	if (last->prev == NULL) {
		listData = last->data;
		first = NULL;
		last = NULL;
	} else {
		DNode* current = last;
		current = last->prev;
		current->next = NULL;
		last = current;
		listData = current->data;
	}
	size--;
	return listData;
}
void DLL::addAtFront(int x) {
	DNode *n = new DNode(x);
	n->next = first;
	first->prev = n;
	first = n;
	size++;
}
void DLL::addFirst(int x) {
	DNode *n = new DNode(x);
	first = n;
	last = n;
	size++;
}
/***************************************************************************************************/
/*Part 2																																		*/
/***************************************************************************************************/
/* write insertAt, removeAtK  here */
void DLL::insertAt(int ind, int x) {
	DNode *current = first;
	DNode *n = new DNode(x);
	for (int i = 1; i < ind; i++) {
		current = current->next;
	}
	if (current == first) {
		n->next = current;
		current->prev = n;
		first = n;
	}
	else if (current == last) {
		current->next= n;
		n->prev = current;
		last = n;
	} else {
		DNode *temp = current->next;
		current->next = n;
		n->prev = current;
		n->next = temp;
		if (temp != NULL) {
			temp->prev = n;
		}
	}
	size++;
}
int DLL::removeAtK(int ind) {
	DNode *current = first;
	int listData;
	for (int i = 1; i < ind; i++) {
		current = current->next;
	}
	if (size == 1) {
		listData = current->data;
		first = NULL;
		last = NULL;
	} else if (ind == 0) {
		listData = current->data;
		first = current->next;
		first->prev = NULL;
	} else {
		listData = current->next->data;
		DNode *listAfterK = current->next->next;
		current->next = listAfterK;
		if (listAfterK != NULL) {
			listAfterK->prev = current;
		}
	}
	size--;
	return listData;
}
/****************************************************************************************/
/* Part 3                                                                                                                       */
/****************************************************************************************/
/* write reverse here */
void DLL::reverse() {
	DNode *current = first;
	while(current != NULL) {
		DNode *temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = temp;
	}
	DNode *tempLast = last;
	last = first;
	first = tempLast;
}
/****************************************************************************************/
/* Part 4                                                                                                                       */
/****************************************************************************************/
// write removeX here
void DLL::removeX(int x, int *ind) {
	DNode *current = first;
	int index = 0;
	while(current->data != x) {
		current = current->next;
		index++;
		if (current == NULL) {
			break;
		}
	}
	*ind = index;
	if (current != NULL) {
		if(current == first) {
			first = current->next;
			first->prev = NULL;
		} else if (current == last) {
			last = current->prev;
			last->next = NULL;
		} else {
			current = current->prev;
			DNode *listAfterI = current->next->next;
			current->next = listAfterI;
			if (listAfterI != NULL) {
				listAfterI->prev = current;
			}
		}
		size--;
	}
}
	
/****************************************************************************************/
/* Part 5                                                                                                                     */
/****************************************************************************************/
/* write skip here */
void DLL::skip(bool flag) {
	DNode *current;
	if (flag) {
		current = first->next;
		current->prev = NULL;
		first = current;
		size--;
	} else {
		current = first;
	}
	bool done = false;
	while(!done) {
		if (current->next == NULL) {
			last = current;
			done = true;
		} else if (current->next->next == NULL) {
			current->next = NULL;
			last = current;
			size--;
			done = true;
		} else {
			DNode *nodeToSkipTo = current->next->next;
			current->next = nodeToSkipTo;
			nodeToSkipTo->prev = current;
			current = nodeToSkipTo;
			size--;
		}
	}
}

/***************************************************************************************************/
/*End of your part																														*/
/***************************************************************************************************/

void DLL::printList() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << ", ";
		tmp = tmp->next;
	}
	cout << endl;
}
void DLL::printCode() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << alpha[tmp->data];
		tmp = tmp->next;
	}
	cout << endl;
}
DLL::~DLL(){
	DNode *tmp = first;
	DNode *tmp2 = first->next;
	while (tmp != NULL) {
		delete tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
}


