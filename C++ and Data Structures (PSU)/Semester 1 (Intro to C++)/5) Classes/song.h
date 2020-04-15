#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Song : public Media {
 public:
  Song();
  virtual int getType();
  char* getPublisher();
  char* getArtist();
  int* getDuration();
 private:
  char publisher[100];
  char artist[50];
  int duration;
};
#endif
