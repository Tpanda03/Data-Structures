#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

class Node {
public:
	Node(char*);
	~Node();
	void setFront(Node*);
	void setBack(Node*);
	Node* getFront();
	Node* getBack();
	bool isBack();
	bool isFront();
	void setNext(Node*);
	Node* getNext();
	char* getOp();
private:
	Node* next;//next node in linked list
	Node* back;//left node to the current node
	Node* front;//right node to the current node
	char* op;
};

#endif //NODE_H_INCLUDED
