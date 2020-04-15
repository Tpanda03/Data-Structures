#include <iostream>
#include <cstring>
#include "media.h"
#include "song.h"

using namespace std;

Song::Song() {

}
int Song::getType() {
  return 2;
}
char* Song::getArtist() {
  return artist;
}
char* Song::getPublisher() {
  return publisher;
}
int* Song::getDuration() {
  return &duration;
}
