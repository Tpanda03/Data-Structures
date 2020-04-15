#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

//Linked List 2, 1/24/2020, This code is meant to add students to a list while arranging in id numbers, delete print averaging options are avaliable. delete looks through the list and deletes by finding unique student id number. average averages the gpas of all students in the list. 

void add(Node *&head, Student* newStudent);//function prototype for adding
void print(Node* next);//function prototype for printing
float average(Node* next);//function prototype for averaging
void remove(Node* next, Node* previous, int id);//function prototype for deleting

Node* head = NULL; 

int main(){//main loop
  int stillPlaying = 0;
  
  while(stillPlaying == 0){
    char* input = new char[50];//for add print delete average or exit
    int inputID = 0;
    cout << "Do you want to add, print, delete, average or exit?" << endl;
    cin.getline(input, 25, '\n');


    if(strcmp(input, "add") == 0){//if user chose add
      char* name = new char[50];//for the name of student
      int id = 0;//for the id of the student
      float gpa = 0;//for the gpa of the student
      
      cout << "Please enter the student's name: ";
      cin.getline(name, 50, '\n');
      cout << endl;
      
      cout << "Please enter the student's ID number: ";
      cin >> id;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl;
    
      cout << "Please enter the student's GPA: ";
      cin >> gpa;
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << endl;

      Student* newStudent = new Student(name, id, gpa);
      add(head, newStudent);
    }
    
    else if(strcmp(input, "print") == 0){
      print(head);//print entire list
    }

    else if(strcmp(input, "exit") == 0){
      stillPlaying = 1;//exit?
    }

    else if(strcmp(input, "delete") == 0){ 
      if (head == NULL) {//if list is empty
	cout << endl << "There are no students to delete" << endl << endl;
      }
      else {
	cout << endl << "What is the studentID of the student you would like to delete?" << endl;
	cin >> inputID;//recieve studentID to delete
	cin.clear();
	cin.ignore(1000000, '\n');
	remove(head, NULL, inputID);//function for deleting
      }
    }
    
    else if(strcmp(input, "average") == 0){ 
      if (head == NULL) {
	cout << endl << "There are no students." << endl << endl;
      }
      else {
	cout << endl << "The average GPA equates to: " << average(head) << endl << endl;
      }
    }

    else {
      cout << "not a valid answer" << endl;
    }
  }
}

void remove(Node* next, Node* previous, int id) {
char choice;
 if (next == head && (next -> getStudent() -> getID() == id)) {//if the head is the chosen student  
    cout << endl << next -> getStudent() -> getName() << " " << endl;
    cout << next -> getStudent() -> getID() << endl;
    cout << next -> getStudent() -> getGpa() << endl;
    cout << "Would you would like to delete this student?" << endl;
    cin >> choice;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (choice == 'y') {//if they agree it is the student
      cout << "Student deleted" << endl << endl;
      if (next -> getNext() == NULL) {//deleting student
	next -> ~Node();
	head = NULL;
      }
      else {//moving it to the end to prep for deleting
	head = next -> getNext();
	next -> ~Node();
	remove(head, NULL, id);
      }
    }
    else if (choice == 'n') {
      cout << "Student not deleted" << endl;
      if (next -> getNext() != NULL) {
	remove(next -> getNext(), next, id);
      }
    }
    else {
      cout << "Invalid input" << endl << endl;
    }
  }
 else if (next -> getStudent() -> getID() == id) {//same function but for in the middle of the linked list
    cout << endl << next -> getStudent() -> getName();
    cout << next -> getStudent() -> getID() << endl;
    cout << next -> getStudent() -> getGpa() << endl;
    cout << "Would you would like to delete this student?" << endl;
    cin >> choice;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (choice == 'y') {//deleting student
      cout << "Student deleted" << endl << endl;
      previous -> setNext(next -> getNext());
      next -> ~Node();
    }
    else if (choice == 'n') {//not deleted
      cout << "Student not deleted" << endl << endl;
    }
    else {
      cout << "Invalid input" << endl << endl;
    }
  }
  if (next -> getNext() != NULL) {
    remove(next -> getNext(), next, id);
  }
}

float average(Node* next) {//average function that averages GPA
  float total = 0;
  int counter = 0;
  if (next == head) {//run through and total up gpa. Also increase counter for division
    total += next -> getStudent() -> getGpa();
    counter++;
  }
  while (next -> getNext() != NULL) {//if the list is at the last object
    total += next -> getNext() -> getStudent() -> getGpa();
    counter++;
    next = next -> getNext();
  }
  return (total/counter);//calculate average
}

void add(Node *&head, Student *newStudent){//add function that adds the student to the end of the linked list
 
  if (head == NULL) { //if the current node has no student
    head = new Node(newStudent); //make a node with the recently made student
    head->setStudent(newStudent);
  }
  else if (head->getStudent()->getID() > newStudent->getID()) { //if head's id > new student's id 
    Node* temp = new Node(head -> getStudent());
    temp -> setStudent(head->getStudent());
    temp -> setNext(head -> getNext());
    head -> setStudent(newStudent);
    head -> setNext(temp);
  }
  else if (head->getNext() == NULL) { //if there is no student in list after head
    Node* temp = new Node(newStudent); //make a node with new student in the empty spot
    temp->setStudent(newStudent);
    head->setNext(temp);
  }
  else if (head->getNext()->getStudent()->getID() > newStudent->getID()) { //if next id > new student id
    Node* temp = new Node(newStudent); //make a node with new student after next node
    temp->setStudent(newStudent);
    temp->setNext(head->getNext());
    head->setNext(temp);
  }
  else {
    Node* next = head->getNext(); //recursion
    add(next, newStudent);
  }
}

void print(Node* next){//print function prints out the whole list
  if(next == head){//if next is equal to the head
    cout << "list: " << endl;//print list
  }
  if(next != NULL){//if it is not null
    cout << "(Name: " << next->getStudent()->getName() << ", ID: " << next->getStudent()->getID() << ", GPA: "  << fixed << setprecision(2) << next->getStudent()->getGpa() << ") "<<endl;//print the name of the student in the node
    print(next->getNext());//recursive function on the next node
  }
}

