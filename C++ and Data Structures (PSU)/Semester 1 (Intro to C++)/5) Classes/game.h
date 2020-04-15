#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Game : public Media {
 public:
  Game();
  virtual int getType();
  char* getPublisher();
  float* getRating();
 private:
  char publisher[100];
  float rating;
};

#endif
