#include <iostream>

#include "fnc.h"
#include "list.h"
#include "node.h"

using namespace std;

int main() {
	fnc* infixTranslator = new fnc();//start the shunting yard algorithm

	cout << "Enter your expression: " << endl;

	char *input = new char[50];
	cin.getline(input, 50, '\n');
	char *token = strtok(input, " ");
	List* newList = new List();//make a new linked list
	while (token != NULL) {
		Node* newNode = new Node(token);//create a new node with the value of token
		newList->enqueue(newNode);//add to linked list
		cout << "token: " << token << endl; //testing purposes
		token = strtok(NULL, " ");
	}
	infixTranslator->setQueue(newList);
	infixTranslator->makePostfix();
}
