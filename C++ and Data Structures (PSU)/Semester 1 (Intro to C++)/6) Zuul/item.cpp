//imports
#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

Item::Item(char* setName){//constructor allows you to set the name of the item
  name = setName;
}

char* Item::getName(){//returns the name of the item
  return name;
}
