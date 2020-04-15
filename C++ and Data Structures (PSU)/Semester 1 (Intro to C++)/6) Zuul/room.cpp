//imports
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

Room::Room(){//blank constructor
}

char* Room::getName(){//returns name of room
  return name;
}

char* Room::getDescription(){//returns description of room
  return description;
}

vector<Item*>* Room::getItems(){//returns the whole item array in a pointer
  return &items;	
}

map<const char*, Room*>* Room::getExits(){//returns whole pointer map of exits
  return &exits;
}

bool Room::isValidRoom(char* room){//returns true if the name of the room is the same as the inputed cstring
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    if(strcmp(it->first, room) == 0){//it->first gets the first value in map(the key)
      return true;
    }
  }
}

Room* Room::getExitRoom(char* room){//returns the exit room pointer from the cstring of the direction
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    if(strcmp(it->first, room) == 0){
      return it->second;
    }
  }
  return 0;//Returns nothing if it does not exist
}

void Room::getExitDirections(){//Prints out all the directions you can exit from
  int i = 0;
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    if(i == 0){
		cout << it->first;
		i++;
	}
	else{
		cout << ", " << it->first;//prints with a comma in the middle
	}
  }
  cout << endl;
}

void Room::addItem(Item* item){//adds item to the room
  items.push_back(item);
}

bool Room::validItem(char* itemName){//checks if the item exits in the room by comparing the name with the inputed string.
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
	  return true;
    }
  }
  return false;
}

void Room::printItems(){//prints names of all the items
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    cout << (*it)->getName() << " ";
  }
  cout << endl;
}


Item* Room::takeItem(char* itemName){//returns a pointer to the item and removes the item from the vector
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
	  Item* i = (*it);
	  it:items.erase(it);
	  return (i);
    }
  }
  return NULL;
}
