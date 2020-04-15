#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

Node* head = NULL;//node that starts out the linked list

void add(char* name, int id, float gpa){//add function that adds the student to the end of the linked list
  Student* newStudent = new Student(name, id, gpa);
  Node* current = head;//creating new current node that is equal to the value at head
  if(current == NULL){//if the head is null
    head = new Node(newStudent);//make a new node for the head
    head->setStudent(newStudent);//set the student for the node equal to the
  }
  else{
    while(current->getNext() != NULL){//while the current pointer is not at the end of the array
      current = current->getNext();//make the current node equal to the next node
    }
    current->setNext(new Node(newStudent));//make a new node at the set next location of the current node
    current->getNext()->setStudent(newStudent);//set the nodes student to the imput of function
  }
}

void print(Node* next){//print function prints out the whole list
  if(next == head){//if next is equal to the head
    cout << "list: " << endl;//print list
  }
  if(next != NULL){//if it is not null
    cout << "(Name: " << next->getStudent()->getName() << ", ID: " << next->getStudent()->getID() << " , GPA: "  << fixed << setprecision(2) << next->getStudent()->getGpa() << ") "<<endl;//print the name of the student in the node
    print(next->getNext());//recursive function on the next node
  }
}

int main(){//main loop
  int stillPlaying = 0;

  while(stillPlaying == 0){
    char* input = new char[50];
    char* studentName = new char[50];
    int id = 0;
    float gpa = 0;
    cout << "Do you want to add or exit?" << endl;
    cin.getline(input, 25, '\n');
    //cin.clear();
    //cin.ignore();

    if(strcmp(input, "add") == 0){
      cout << "Type name of student:" << endl;
      cin.getline(studentName, 25, '\n');
      
      cout << "Type ID of student:" << endl;
      cin >> id;
      cin.clear();
      cin.ignore(1000000, '\n');
      
      cout << "Type GPA of student: " << endl;
      cin >> gpa;
      cin.clear();
      cin.ignore(1000000, '\n');

      add(studentName, id, gpa);
      print(head);
    }
    else if(strcmp(input, "exit") == 0){
      stillPlaying = 1;
    }
    else {
      cout << "not a valid answer" << endl;
    }
  }
}
