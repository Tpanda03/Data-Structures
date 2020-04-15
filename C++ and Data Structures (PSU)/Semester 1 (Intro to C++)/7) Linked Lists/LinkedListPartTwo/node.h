#ifndef NODE_H
#define NODE_H
//header guard ^^

//imports vv
#include <iostream>
#include "student.h"

using namespace std;

class Node{
 public: //public functions
  Node(Student* user); //constructor
  ~Node(); //destructor 
  void setStudent(Student* user); //set new student, sets "newstudent" = "user"
  Student* getStudent(); //get student pointer, returns "newstudent"
  void setNext(Node* user); //set where node points to
  Node* getNext(); //get the node pointer, returns "next"
  
 private:
  Student* newstudent;
  Node* next;
};

#endif
