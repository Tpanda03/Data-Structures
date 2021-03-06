#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

using namespace std;

struct Person{//what every person has when added to the system
  char firstname[20];
  char lastname[20];
  int studentid;
  float gpa;
};
//referencing  the methods
Person* ADD();
void PRINT(vector<Person*> students);
void DELETE(vector<Person*>* students, int studentid);

int main() {
  bool quit = false;//quit condition
  char input[10];
  vector<Person*> students;
  int IDinput;//this is to pick a id number to delete a student from the directory
  while(!quit){//while loop until the user wants to do nothing more for the database
    cout << "Would you like to perform a task? (ADD, PRINT, DELETE, QUIT)" << endl;
    cin.get(input, 10);
    cin.clear();
    cin.ignore(1000000, '\n');
    if ((strcmp(input, "print") == 0) || (strcmp(input, "PRINT") == 0)){//if user said print or PRINT 
      PRINT(students);//run print method
    }
    else if ((strcmp(input, "delete") == 0) || (strcmp(input, "DELETE") == 0)){//if user said delete or DELETE
      cout << "Enter the ID number of the student you would want to remove: " << endl;
      cin >> IDinput;//get the id number of the student they want to delete
      cin.clear();
      cin.ignore(1000000, '\n');
      DELETE(&students, IDinput);//run delete method
    }
    else if ((strcmp(input, "add") == 0) || (strcmp(input, "ADD") == 0)){//if user said add or ADD
      students.push_back(ADD());//run add method
    }
    else if ((strcmp(input, "quit") == 0) || (strcmp(input, "QUIT") == 0)){//if user said quit or QUIT
      quit = true;//make quit true and break out of the while loop
    }
    else{
      cout << "Your response to my question is invalid... please type a valid response" << endl;//if they usere didnt say anything like print add delete or quit
    }
  }
  return 0;
}

Person* ADD(){//add method
  Person* newPpl = new Person();
  cout << "What is the student's first name? " << endl;//get firstname
  cin >> newPpl->firstname;
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "What is the student's last name? " << endl;//get lastname
  cin >> newPpl->lastname;
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "What is the student's ID number? " << endl;//get id number
  cin >> newPpl->studentid;
  cin.clear();
  cin.ignore(1000000, '\n');
  cout << "What is the student's gpa? " << endl;//get gpa
  cin >> newPpl->gpa;
  cin.clear();
  cin.ignore(1000000, '\n');
  return newPpl;
}

void PRINT(vector<Person*> students){//print method
  vector<Person*>::iterator b;
  for(b = students.begin(); b != students.end(); ++b) {
    cout << "Name: " << (*b)->firstname << " " << (*b)->lastname << endl;//print first and last name
    cout << "StudentID Number: " << (*b)->studentid << endl;//print student id
    cout << "GPA: " << fixed << setprecision(2) << (*b)->gpa << endl;//print student gpa
    cout << " " << endl;
  }
}

void DELETE(vector<Person*>* students, int studentid) {//delete method
  vector<Person*>::iterator a;
  for(a = students->begin(); a != students ->end(); ++a) {
    if((*a)->studentid == studentid){
      delete *a;
      students->erase(a);
      return;
    }
  }
  cout << "That ID is may be invalid or not yet registered into the database" << endl;//if invalid id is entered 
}


