#include "list.h"
#include "node.h"

List::List() {//constructor
	head = NULL;
	tail = NULL;
}

List::~List() {

}

void List::push(Node* n) {//adds the node at the front
	if(empty() == true) {//if the list is empty
		head = n;
		tail = n;
	}
	else {//if it is not empty
		n->setNext(head);
		head = n;
	}
}

void List::pop() {//removes from the front
	if (empty() != true) {//if list is not empty
		Node* temp = head;
		head = head->getNext();
		delete temp;
	}
	else if (head == 0) {//if head is null
		head = 0;
		tail = 0;
	}
	else {
		cout << endl;
	}
}
void List::remove() {//removes from the front and does not delete the node
	if (empty() != true) {//if not empty
		head = head->getNext();
	}
	else if (head == 0) { //if head is null while stack isnt empty to prevent stack lyse cases
		head = 0;
		tail = 0;
	}
	else {
		cout << endl;
	}
}

Node* List::peek() {//returns the top
	return head;
}

void List::enqueue(Node* n) {//add to end of queue
	if(empty() == true) {
		head = n;
		tail = n;
	}
	else {
		tail->setNext(n);
		tail = n;
	}
}

void List::dequeue() { //remove from front of queue
	if (empty() != true) {
		Node* temp = head;
		head = head->getNext();
		delete temp;
	}
	else if (empty()) {
		head = 0;
		tail = 0;
	}
	else {
		cout << endl;
	}
}

bool List::empty() {
	if (head == 0) {//if the head is null
		tail = 0;
		return true;
	}
	else {
		return false;
	}
}

Node* List::getHead() {
	return head;
}

Node* List::getTail() {
	return tail;
}
