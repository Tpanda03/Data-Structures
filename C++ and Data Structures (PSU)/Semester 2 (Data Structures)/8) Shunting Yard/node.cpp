#include <iostream>
#include "node.h"

Node::Node(char* setOp) { //constructor
	next = NULL;
	back = NULL;
	front = NULL;
	op = setOp;
}

Node::~Node() {
	
}


void Node::setFront(Node * newFront) { //set the input to front node
	front = newFront;
}

void Node::setBack(Node * newBack) { //set input to back node
	back = newBack;
}

Node * Node::getFront() {
	return front;
}

Node * Node::getBack() {
	return back;
}

bool Node::isBack() {
	if (back != NULL) {//if there is a back node return true
		return true;
	}
	else {
		return false;
	}
}

bool Node::isFront() {
	if (front != NULL) {//if there is a front node return true
		return true;
	}
	else {
		return false;
	}
}

void Node::setNext(Node* newNext) {
	next = newNext;//set next to input
}

Node* Node::getNext() {
	return next;//return next node
}

char* Node::getOp() {
	return op;
}
