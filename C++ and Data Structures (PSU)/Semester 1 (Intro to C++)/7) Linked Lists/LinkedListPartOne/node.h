#ifndef NODE_H
#define NODE_H
//imports
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node{
 public:
  Node(Student*);//constructor
  ~Node();//destructor
  void setStudent(Student*);//set the student
  Student* getStudent();//returns the student pointer
  void setNext(Node* newNext);//sets the name
  Node* getNext();//Returns the next node in the linked list
 private:
  Student* student;//Student node holds
  Node* next;//next node in linked list
};

#endif
