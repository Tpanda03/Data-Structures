//inports
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

class Parser{
 public:
  bool processCommand(char*, Player*);//prosesses the user inputed commands
 private:
  char* substr(char*, int, int);//the idea to make this came from andrew - returns substring of char
};

#endif
