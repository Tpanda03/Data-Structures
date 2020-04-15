//imports
#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student*){//constructor
  student = NULL; //set student to null
  next = NULL;//sets value to null
}

Node::~Node(){//deconstructor
  delete &student;//deletes the student value
  next = NULL;//sets next to null
}

void Node::setStudent(Student* newStudent){//set the student
  student = newStudent;//sets student to input
}

Student* Node::getStudent(){//returns the student
  return student;
}

void Node::setNext(Node* newNext){//gets next node
  next = newNext;//sets next to the inputed node
}

Node* Node::getNext(){//returns the next node
  return next;//returns next node
}
