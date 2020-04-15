#include <iostream>
#include <cstring>

#include "list.h"
#include "fnc.h"
#include "node.h"

using namespace std;

fnc::fnc() {//constructor
  List* expressionQueue = new List();//initializes expressionQueue
  stillPlaying = true;
}

fnc::~fnc() {

}

void fnc::infixTool(Node* binTree) {
	if (isOperator(*binTree->getOp())) {//if the op in the node is an operator
		cout << "( ";
	}
	if (binTree->getBack() != NULL) {//if there is a back node
		infixTool(binTree->getBack());//recursivly call infix on the back node
	}
	if (binTree->getFront() != NULL) {//if there is a front node
		infixTool(binTree->getFront());//recursivly call infixTool on the front node
	}
	if (isOperator(*binTree->getOp())) {//if the op in the node is an operator
		cout << ") ";
	}
  cout << binTree->getOp() << " ";//print out the op
}

void fnc::postfixTool(Node* binTree) {
	if (binTree->isBack()) {//if there is a back node
  		postfixTool(binTree->getBack());//recursivly call postifix on the back node
	}
	if(binTree->isFront()) {//if there is a front node
	   postfixTool(binTree->getFront());//recursivly call postfix on the front node
	}
  cout << binTree->getOp() << " ";//print out the op in the node
}

void fnc::prefixTool(Node* binTree) {
  cout << binTree->getOp() << " ";//print out the op in the node
  if (binTree->getBack() != NULL) {//if there is a back node
  		prefixTool(binTree->getBack());//recursivly call prefix on the back node
	}
	if(binTree->getFront() != NULL) {//if there is a front node
		prefixTool(binTree->getFront());//recursivly call prefix on the front node
	}
}

List* fnc::getQueue() {
	return expressionQueue;//returns the input queue
}

void fnc::setQueue(List * newQ) {//allows you to set the input Q outside the class
	expressionQueue = newQ;//sets expressionQueue eaqual to the inputed list
}

bool fnc::isOperator(char op) {//returns true if it is an operator
 switch(op){
   case '+': return true;
   case '-': return true;
   case '*': return true;
   case '/': return true;
   case '^': return true;
   case '(': return true;
   case ')': return true;
   default: return false;
 }
}

int fnc::precedence(char op) {//returns the prededence of the operator
  switch(op){
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    case '^': return 4;
     default: return 0;
  }
}

void fnc::makePostfix() {
	List* stack = new List();
	List* operatorStack = new List();

	//run through expressionQueue
	while (expressionQueue->empty() != true) {
		char* headOp = expressionQueue->getHead()->getOp();//sets variable headOp eaqual to the op at head
		if (!isOperator(*headOp)) {//if the first char in the char[] is not a operator then ...
			Node* newNode = new Node(headOp);//push the head to the stack
			stack->push(newNode);
			expressionQueue->dequeue();
		}
		else {//if it is an operator
			if (*headOp == '(') {//if it is a (
				Node* newNode = new Node(headOp);//push it straight to the operatorStack
				operatorStack->push(newNode);
				expressionQueue->dequeue();
			}
			else if(*headOp != ')') {//if it is not a end perenthases
				int pred = precedence(*headOp);//calc precedence of the operator
				if (operatorStack->peek() != NULL) {//if there is stuff in the operator stack
					if (pred != 1) {//as long as the prededence is not 1
						while(operatorStack->peek() != NULL && precedence(*operatorStack->peek()->getOp()) > pred) {//while there is not nothing in the operatorStack and the prededence of the top of the opperator stack is more than the incoming operator...
							//push the top of the operator stack to the stack
							Node* newNode = new Node(operatorStack->peek()->getOp());
							stack->push(newNode);
							operatorStack->pop();
						}
						//push the incoming operator to the stack
						Node* newNode = new Node(headOp);
						operatorStack->push(newNode);
						expressionQueue->dequeue();
					}
					else {//if eaqual to 1 print this message
						cout << "You entered an invalid operator" << endl;
						return;
					}
				}
				else {
					//if there is nothing in the operator stack push straight to the stack
					Node* newNode = new Node(headOp);
					operatorStack->push(newNode);
					expressionQueue->dequeue();
				}
			}
			else {//if it is a end perentheses
				while (*operatorStack->peek()->getOp() != '(') {//while there isnt a ( at the top of the operator stack then...
					//push the items at the top of the operatior stack to the stack
					Node* newNode = new Node(operatorStack->peek()->getOp());
					stack->push(newNode);
					operatorStack->pop();
				}
				//get rid of the ( and )
				expressionQueue->dequeue();
				operatorStack->pop();
			}
		}
	}
	while (operatorStack->empty() != true) {//while the operator stack is not empty
		//push items from the top of the operator stack to the stack
		Node* newNode = new Node(operatorStack->peek()->getOp());
		stack->push(newNode);
		operatorStack->pop();
	}
	Node* current = stack->getHead();//set current to the head of stack
	List* expressionQueue = new List();//reintialize the list
	while (0 != current) {//while the current node is not NULL
		//push the current node to the expressionQueue
		Node* newNode = new Node(current->getOp());
		expressionQueue->push(newNode);
		current = current->getNext();
	}
	makeTree(expressionQueue);//make the tree
}

void fnc::makeTree(List* input) {
	List* tree = new List();//make new list for tree
	while (input->empty() != true) {//while the input is not empty
		if(isdigit(*input->peek()->getOp())) {//if the first char of input is a digit
			//push the input head to the tree list
			Node* filler = new Node(input->peek()->getOp());
			tree->push(filler);
			input->dequeue();
		}
		else {
			Node* currentNode = new Node(input->peek()->getOp());//create node for operator
			currentNode->setFront(tree->peek());//set front node to the head of tree
			tree->remove();//take the head out of tree
			currentNode->setBack(tree->peek());//set back node to the head of tree
			tree->remove();//take out the head of tree
			tree->push(currentNode);//add the operator to the tree
			input->dequeue();//take the head out of the input queue
		}
	}
  while (stillPlaying == true) {
  	cout << "Do you want to see infix, postfix, prefix: ";
  	char *choice = new char[50];
  	cin.getline(choice, 50, '\n');//get user input

  	if (strcmp(choice, "infix") == 0) {//if user inputs infix
  		infixTool(tree->peek());//run infix with using head of tree
  		cout << endl;
      stillPlaying = false;
  	}
  	else if (strcmp(choice, "postfix") == 0) {//if user inputs postfix
  		postfixTool(tree->peek());//runs postfix using head of tree
  		cout << endl;
      stillPlaying = false;
  	}
  	else if (strcmp(choice, "prefix") == 0) {//if user inputs prefix
  		prefixTool(tree->peek());//runs prefix using head of tree
  		cout << endl;
      stillPlaying = false;
  	}
    else {
      cout << "Invalid option." << endl;
    }
  }
}
