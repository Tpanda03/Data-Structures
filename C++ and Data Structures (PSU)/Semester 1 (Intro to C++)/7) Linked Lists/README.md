Linked List (Project #7, Completed Part 1: December-13 2019, Completed Part 2: January-20 2019)

**Linked List Part 1**

You will be creating the first part of a student list program that uses linked lists. You must create a Node class. It will include a pointer to a Student class (not struct).

Variables required: Student*, Node*

Functions required:

Node* getNext() //get next Node pointer (10 points)

Student* getStudent() //get student pointer (10 points)

void setNext(Node*) //set the next pointer to the corresponding node pointer (10 points)

Node(Student*) //constructor (10 points)

~Node() //destructor (10 points)

Make sure you test and document your project thoroughly! Comments go into the .h file. Your code is going to be given to someone else for the second part of the project.

Turn in the project as a repository with Node.cpp, Node.h, and any other code that is necessary to prove your Node class works. (Main.cpp, Student.cpp, etc.) This url is the one you will turn in for this project. 

Also, create a second repository which only contains Node.h and an object file, Node.o, in place of Node.cpp. (An object file is created by compiling the code the "-c" flag.) This repository is the one you will share with someone else in the second half of the project. MAKE SURE YOU COMPILE THIS IN CYGWIN IN THE LAB. It matters what platform you compile it on. The .cpp can be made anywhere; it's only the .o file that is platform specific.

**Linked Lists Part 2**

The Idea

Change your project Student List to use linked lists and a student class.  You will need to use recursion for a number of these requirements! Also, no vectors are allowed in this project.

Use the provided Node class (Node.o and Node.h) from your partner that has a pointer to the next node and a Student pointer. (20 points)

THE PERSON WHO IS PROVIDING YOUR CODE SHOULD NOT, UNDER ANY CIRCUMSTANCES, PROVIDE YOU THE NODE.CPP FILE. That would result in people getting a zero on the first part of this project...

Your project should have all the same functions that you had for Student List.

 

When you type in: ADD

You should create a new entry for a student.  After you type in add, the program should prompt for first name, last name, student id, and GPA.  You should then insert a new node into your linked list, sorting it by student id number (least to greatest). USE RECURSION. (20 points)

 

When you type in: PRINT

Your program should print out all the students currently stored.  For example:

 

Andrew Jeddeloh, 468921, 0.12

Jason Galbraith, 487329, 5.00

Josh Bowles, 903826, 3.25

 

The GPA should be shown to two decimal places. USE RECURSION. (20 points)

 

When you type in: DELETE

Prompt the user for the student id number to delete, and remove that node from the linked list.  Make sure you maintain your links correctly.  Make sure you use a destructor to remove unused memory!  Watch out for the case when you have an empty list. USE RECURSION. (20 points)

 

Add two more functions:
QUIT, which quits the program, and

AVERAGE, which prints the GPA average of all students, shown to two decimal places. (10 points)

 

Comments. (10 points)

 

Total: 100 points
