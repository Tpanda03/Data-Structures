#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include "tree.h"

using namespace std;
//Takes in numbers from file
//Format 1 2 3 4
void from_file(Tree* t, const char* path){
	std::ifstream file(path);
	char c;
	char token[100];
	for(int i = 0; i < sizeof(token); i++) token[i] = 0;
	int position = 0;
	while(file.get(c)){
		if(c == ' '){
			t->insert(atoi(token));
			position = 0;
			for(int i = 0; i < sizeof(token); i++) token[i] = 0;
		}else {
			token[position] = c;
			position++;
		}
	}
}
int main(){
	Tree t = Tree();
	char* input = new char[10];
	while(true){
		cout << "Enter command(input, exit, print, output): ";
		cin.get(input, 10);
		cin.clear();
		cin.ignore(100, '\n');

		if(strcmp(input, "input") == 0){
			cout << "File or Manual input(file,manual): ";
			cin.get(input, 10);
			cin.clear();
			cin.ignore(100, '\n');

			if(strcmp(input, "file") == 0){
				char* filepath = new char[200];
				cout << "Enter path: ";
				cin.get(filepath, 200);
				cin.clear();
				cin.ignore(100, '\n');

				from_file(&t, filepath);
				delete[] filepath;
			}else if(strcmp(input, "manual") == 0){
				char* number = new char[10];
				while(true){
					cout << "Enter number(type exit to leave): ";
					cin >> number;
					cin.clear();
					cin.ignore(100, '\n');

					if(strcmp(number, "exit") == 0)
						break;
					t.insert(atoi(number));
				}
				delete[] number;
			}
		}else if(strcmp(input, "exit") == 0){
			break;
		}else if(strcmp(input, "print") == 0){
			t.print(true);
		}else if(strcmp(input, "output") == 0){
			t.print(false);
		}else if(strcmp(input, "remove") == 0){
			cout << "Enter number to remove: ";
			cin.get(input, 10);
			cin.clear();
			cin.ignore(100, '\n');

			t.remove(atoi(input));
		}else{
			cout << "Not sure what that command is..." << endl;
		}
	}
	delete[] input;
	return 0;
}
