//imports
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

class Player{//look on .cpp file for comments on what each does
 public:
  Player(Room*);//constructor
  //Getters & Setters
  char* getName();
  Room* getCurrentRoom();
  vector<Item*>* getItems();
  void setCurrentRoom(Room*);
  //item management
  void addItem(Item*);
  Item* takeItem(char*);
  void printInventory();
  bool validItem(char*);
  bool keyItem(char*);
private:
  char name[50];
  vector<Item*> items;
  Room* currentRoom;
};

#endif
