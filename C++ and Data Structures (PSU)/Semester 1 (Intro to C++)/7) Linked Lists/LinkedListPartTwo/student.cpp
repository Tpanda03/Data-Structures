
//imports
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(const char* setName, int setID, float setGpa){//constructor
  name = new char[50];
  strcpy(name, setName);//sets the name to the input
  id = setID;//sets id to the input
  gpa = setGpa; //set gpa to input
}

Student::~Student(){//destructor
  delete name;
}

char* Student::getName(){//returns the name of the student
  return name;//retruns name
}

int Student::getID(){//returns the id of student
  return id; //returns id
}

float Student::getGpa(){//returns the gpa of student
  return gpa; //returns gpa
}
