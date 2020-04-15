//inports
#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;

Player::Player(Room* startRoom){//constructor
  currentRoom = startRoom;//sets input to startRoom
}

char* Player::getName(){//returns name
  return name;
}

Room* Player::getCurrentRoom(){//returns currentRoom
  return currentRoom;	
}

vector<Item*>* Player::getItems(){//returns the address of items
  return &items;	
}

void Player::setCurrentRoom(Room* newRoom){//allows you to change the current room
  currentRoom = newRoom;
}

void Player::addItem(Item* item){//adds item to items vector
  items.push_back(item);
}

Item* Player::takeItem(char* itemName){//returns item and removes it from item vector
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
      Item* i = (*it);
	  it = items.erase(it);//prevents segfault
	  return (i);//returns the item
    }
  }
  return 0;
}

bool Player::validItem(char* itemName){//if the item with the inputed name exists reutrn true
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){//iterator
    if(strcmp((*it)->getName(), itemName) == 0){
	  return true;
    }
  }
  return false;
}
bool Player::keyItem(char* itemName){//if the inputed Item has the same name as any of the cstrings in the array then it returns true
  const char str[5][50] = {"Snow Cone Machine", "Fedora", "Pumpkin", "Rubber Ducky", "Banana"};//array of cstrings giving essential titles
  for(int i = 0; i < 5; i++){
    if(strcmp(str[i], itemName) == 0){
	  return true;
    }
  }
  return false;
}


void Player::printInventory(){//prints out names of items in inventory
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    cout << "\"" << (*it)->getName() << "\"" << " ";
  }
  cout << endl;
}
