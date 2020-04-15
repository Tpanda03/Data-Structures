#include <iostream>
#include <cstring>
#include "media.h"
#include "movie.h"

using namespace std;

Movie::Movie() {

}
int Movie::getType() {
  return 0;
}
char* Movie::getDirector() {
  return director;
}
int* Movie::getDuration() {
  return &duration;
}
float* Movie::getRating() {
  return &rating;
}
