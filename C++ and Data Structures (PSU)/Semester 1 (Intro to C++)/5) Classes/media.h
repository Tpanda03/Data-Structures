#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media{
 public:
  Media();
  int* getYear();
  char* getTitle();
  virtual int getType();
 private:
  int year;
  char title[100];		   
};

#endif
