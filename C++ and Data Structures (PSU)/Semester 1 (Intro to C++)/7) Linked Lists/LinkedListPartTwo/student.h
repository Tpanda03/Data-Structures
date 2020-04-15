//header guard
#ifndef STUDENT_H
#define STUDENT_H
//imports
#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student(const char*, int, float);//constructor
  ~Student();//deconstructor
  char* getName();//returns the name of the student
  int getID();//returns the ID of the student
  float getGpa();
 private:
  char* name = new char[50];//name of student
  int id;//id of the student
  float gpa;
};

#endif


