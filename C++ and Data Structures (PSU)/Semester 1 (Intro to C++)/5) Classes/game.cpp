#include <iostream>
#include <cstring>
#include "media.h"
#include "game.h"

using namespace std;

Game::Game() {

}
int Game::getType() {
  return 1;
}
char* Game::getPublisher() {
  return publisher;
}
float* Game::getRating() {
  return &rating;
}
