#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

using namespace std;
//Reads in a file containing numbers seperated by commas and adds them to the tree
void from_file(Tree* t, const char* path){
	ifstream file(path);
	char c;
	char token[100]; //Holds the characters
	for(int i = 0; i < sizeof(token); i++) token[i] = 0; //Fill with 0s
	int position = 0;
	while(file.get(c)){ //Loops over characters
		if(c == ','){ //When it hits a comma
			t->insert(atoi(token)); //Adds the number
			position = 0;
			for(int i = 0; i < sizeof(token); i++) token[i] = 0; //Clears the string
		}else {
			token[position] = c; //Adds the character to the string
			position++;
		}
	}
	if(strlen(token) > 0) //Adds a number at the end if the file wasn't closed with a comma
		t->insert(atoi(token));
}
int main(){
	Tree t = Tree();
	char* input = new char[10];
	while(true){
		cout << "Enter command(input, search, print, exit): ";
		cin.get(input, 10);
		cin.clear();
		cin.ignore(100, '\n');

		if(strcmp(input, "input") == 0){
			cout << "File, Random, or Manual input(file,random,manual): ";
			cin.get(input, 10);
			cin.clear();
			cin.ignore(100, '\n');

			if (strcmp(input, "random") == 0) {
				int count;
				int i = 0;
				srand(time(0));	//seed generator
				cout << "How many numbers? ";
				cin >> count;
				cin.clear();
				cin.ignore();
				
				while (i != count) {
					int number = rand() % 101;
					t.insert(number);
					i++;
				}
				t.print(t.root, 0); //Print after it adds them
			}
			else if(strcmp(input, "file") == 0){ //If the numbers are coming from a file
				int count = 0;
				char filePath[200];
				char *fileName;
				cout << "Enter file name (does not matter if you type \".txt\"): ";
				cin.getline(filePath, 200, '\n');
				for (int i = 0; i != strlen(filePath); i++) {
					if (filePath[i] == '.') {
						count++;
					}
					else {}
				}
				if (count == 1) {
					fileName = new char[strlen(filePath)];
					fileName = filePath;
				}
				else {
					strcat(filePath, ".txt");
					cout << "filePath: " << filePath << endl;
					fileName = new char[strlen(filePath)];
					fileName = filePath;
				}
				
				from_file(&t, fileName);
				t.print(t.root, 0); //Print after it adds the numbers

			}else if(strcmp(input, "manual") == 0){ //If they're being manually entered
				char* number = new char[10];
				while(true){ //Keep reading in numbers from the user as long as they're entering them
					cout << "Enter number(type exit to leave): ";
					cin >> number;
					cin.clear();
					cin.ignore(100, '\n');

					if(strcmp(number, "exit") == 0)
						break; //Leave when they type exit
					t.insert(atoi(number));
					t.print(t.root, 0); //Print after it adds them

				}
				delete[] number;
			}
		}else if(strcmp(input, "search") == 0){
			char* number = new char[10];
			cout << "Enter number: ";
			 cin >> number;
			cin.clear();
			cin.ignore(100, '\n');

			if(t.search(atoi(number)) == 0)
				cout << number << " doesn't exist in the tree" << cin;
			else{
				t.searchPrint(t.root, 0, atoi(number));
			}
			delete[] number;
		}else if(strcmp(input, "exit") == 0){
			break; //Leave when they type exit
		}else if(strcmp(input, "print") == 0){
			t.print(t.root, 0); //Print the tree from the root
		}else{
			cout << "Not sure what that command is..." << cin;
		}
	}
	delete[] input;
	return 0;
}
