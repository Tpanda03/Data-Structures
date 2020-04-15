//imports
#include <iostream>
#include <string.h>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"
#include "parser.h"

using namespace std;

char* Parser::substr(char* str, int start, int end){//returns substring of cstring
  char* sub = new char[end-start+1];//allocate to heap (andrew told me to do it like this)
  int x = 0;//counter int
  for(int i = start; i < end; i++){
    sub[x] = str[i];//make characters eaqual
    x++;//add one to the counter
  }
  return sub;//return the substring
}

bool Parser::processCommand(char* str, Player* player){//this is the command that is used when you enter something in to the console it executes the commands
  if(strncmp(str, "go ", 3) == 0){//I took this idea from andrew chesters code - finds if the first 3 characters are "go "
    char* direction = substr(str, 3, strlen(str) + 1);//gets the direction by finding the substring after "go "
    if(player->getCurrentRoom()->isValidRoom(direction)){//finds if the desired direction exists
      player->setCurrentRoom(player->getCurrentRoom()->getExitRoom(direction));//sets the current room of player to that
      cout << player->getCurrentRoom()->getDescription() << endl;//prints out the description of current room
      delete direction;//deletes the direction char
    }
    else{
      cout << "That is not a valid direction" << endl;
    }
  }
  else if(strncmp(str, "take ", 5) == 0){//are first 5 char "take "
	char* ItemName = substr(str, 5, strlen(str) + 1);//gets the object name by finding the substring after "go "
	if(player->getCurrentRoom()->validItem(ItemName)){//checks if the room has the item
		player->addItem(player->getCurrentRoom()->takeItem(ItemName));//adds it to the item array of player and removes it from the room
		cout << "You now have " << ItemName << endl;
	}
	else{
		cout << "Not a valid item!" << endl;
	}
  }
  else if(strcmp(str, "help") == 0){//print out help string if you are stuck
	cout << "You got kidnapped! To escape find all 5 items in his labrynth. But be aware, if you give him less than 5 items or they are not the ones that he wanted you to give him, his henchmen will kill you!" << endl << "The commands you can use are \"go\", \"inventory\", \"take\", \"drop\", \"room items\", \"exits\" and \"exit\"" << endl << "If you want to check if your answer is correct enter \"give\"" << endl;
  }
  else if(strncmp(str, "drop ", 5) == 0){//are first 5 char "drop "
	char* ItemName = substr(str, 5, strlen(str) + 1);//gets the object name by finding the substring after "go "
	if(player->validItem(ItemName)){//checks if the player has the item
		player->getCurrentRoom()->addItem(player->takeItem(ItemName));//adds it to the item array of room and removes it from the player
		cout << "You dropped the " << ItemName << endl;
	}
	else{
		cout << "Not a valid item!" << endl;
	}
  }
  else if(strcmp(str, "exits") == 0){//prints out exits of current room
    player->getCurrentRoom()->getExitDirections();
  }
  else if(strcmp(str, "inventory") == 0){//prints out inventory of player
    player->printInventory();
  }
  else if(strcmp(str, "room items") == 0){//prints out he items in the room
    player->getCurrentRoom()->printItems();
  }
  else if(strcmp(str, "give") == 0){//initiates win condition
	if(strcmp(player->getCurrentRoom()->getName(), "Interogation Room") == 0){//make sure player is in same room as curious george
		char str2[50];//cstring that are needed to compare inputs
		char str3[50];
		char str4[50];
		char str5[50];
		char str6[50];
		cout << "Item 1: ";
		cin.get(str2, 50);//input for str2
		cin.clear();
		cin.ignore(10000, '\n');
		if(player->validItem(str2)){//does the player have the item
		  if(player->keyItem(str2)){//is it one of the essetial items?
			  cout << "Item 2: ";
			  cin.get(str3, 50);//get second input
			  cin.clear();
			  cin.ignore(10000, '\n');
			  if(strcmp(str3, str2) != 0){//are the first and second inputs the same
				if(player->validItem(str3)){//does the player have the item
				  if(player->keyItem(str3)){//is it one of the essetial items?
					  cout << "Item 3: ";
					  cin.get(str4, 50);
					  cin.clear();
					  cin.ignore(10000, '\n');
					  if((strcmp(str4, str2) != 0) && (strcmp(str4, str3) != 0)){//is it the same as any of the privious strings
						if(player->validItem(str4)){//does the player have the item
						  if(player->keyItem(str4)){//is it one of the essetial items?
							  cout << "Item 4: ";
							  cin.get(str5, 50);//input for the the 4th item 
							  cin.clear();
							  cin.ignore(10000, '\n');
							  if((strcmp(str5, str2) != 0) && (strcmp(str5, str3) != 0) && (strcmp(str5, str4) != 0)){//is it the same as any of the privious strings
								if(player->validItem(str5)){//does the player have the item
								  if(player->keyItem(str5)){//is it one of the essetial items?
									  cout << "Item 5: ";
									  cin.get(str6, 50);
									  cin.clear();
									  cin.ignore(10000, '\n');
									  if((strcmp(str6, str2) != 0) && (strcmp(str6, str3) != 0) && (strcmp(str6, str4) != 0) && (strcmp(str6, str5) != 0)){//same as before
										if(player->validItem(str6)){
										  if(player->keyItem(str6)){
											  //print out win statement and return false so game ends
											  cout << "The villian applauds your efforts and is happy to announce that you brought him all the correct items. You escape... finally." << endl;
											  return false;
										  }
										}
									  }
								  }
								}
							  }
						  }
						}
					  }
				  }
				}
			  }
		  }
		}
		//print out lose statement and end the game by returning false
		cout << "\"You are incorrect just like I suspected. Henchmen take care of this imbecile.\"" << endl;
		cout << "A buff man walks out from the shadows and shines the light on his face. It was Mr.Galbraith!" << endl;
		cout << "\"I always knew you were the one playing videogames in the class and I am not suprized to see that you failed\"" << endl;
		cout << "Galbraith picks you up with his telepathic powers and drags you to the jail cell. He thows you inside and locks it." << endl;
		cout << "He then uses a destructor on the key and you are stuck forever, or until you restart the code that is..." << endl << "You lose!!!!!!";
		return false;
	}
	else{
	  cout << "You need to be in the interogation room to give the items" << endl;
	  return true;
	}
  }
  else if(strcmp(str, "exit") == 0){//returns false 
	cout << "Thanks for Playing!!!! By Tejash Panda, Class of 2020" << endl;
    return false;
  }
  else{
	cout << "That is not a valid command" << endl;
  }
  return true;
}
