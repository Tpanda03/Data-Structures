#ifndef FNC_H_INCLUDED
#define FNC_H_INCLUDED

#include <iostream>
#include <cstring>
#include "list.h"

using namespace std;

class fnc {
public:
	fnc();//constructor
	~fnc();
	List* getQueue();
	void setQueue(List*);
	void makePostfix();
	void makeTree(List*);
	void infixTool(Node*);
	void postfixTool(Node*);
	void prefixTool(Node*);
private:
	bool isOperator(char);
	int precedence(char);
	bool stillPlaying;
	List* stack;
	List* operatorStack;
	List* expressionQueue;
};

#endif //FNC_H_INCLUDED
