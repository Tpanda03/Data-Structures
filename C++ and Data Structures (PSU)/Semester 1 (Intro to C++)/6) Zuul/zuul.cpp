//imports
#include <iostream>
#include <cstring>
#include "room.h"
#include "player.h"
#include "parser.h"

using namespace std;

int main()//main loop
{
  //initialization of variables
  Parser parser;//creating a new parser object to use those fuctions
  char str[50];//cstring for input
  bool running = true;//running variable
  //intro script
  cout << "You see a white light flash before your eyes. The next thing you know you are in a dark room with your hands handcuffed behind your back." << endl;
  cout << "You got kidnapped! To escape find all 5 items in his labrynth. But be aware, if you give him less than 5 items or they are not the ones that he wanted you to give him, his henchmen will kill you!" << endl << "The commands you can use are \"go\", \"inventory\", \"take\", \"drop\", \"room items\", \"exits\" and \"exit\"" << endl << "If you want the kidnapper to check if your answer is correct enter \"give\"" << endl;
  //Room INIT
  //First Layer
  Room* room1_1 = new Room();//creates room object
  strcpy(room1_1->getName(), "Interogation Room");//changes name to desired name(in this case "Interogation Room")
  strcpy(room1_1->getDescription(), "You are in the interogation room!The villian is in this room along with a few of his hechmen. It is pitch dark exept for one lamp illuminating his's face");
  //the above changes the description of the room
  //repeted below
  Room* room2_1 = new Room();
  strcpy(room2_1->getName(), "Jail Cell");
  strcpy(room2_1->getDescription(), "You are in the jail cell. There are cells lining the wall. Each is packed to the brim with moss. There is an ungodly scent in the room and there are no other exits");
  Room* room3_1 = new Room();
  strcpy(room3_1->getName(), "Villian's Bedroom");
  strcpy(room3_1->getDescription(), "You are in the bedroom. It is covered with moss from the floor to the ceiling.");
  Room* room4_1 = new Room();
  strcpy(room4_1->getName(), "Garden");
  strcpy(room4_1->getDescription(), "You are in the Garden. There are pretty flowers everywhere.");
  Room* room5_1 = new Room();
  strcpy(room5_1->getName(), "Barn");
  strcpy(room5_1->getDescription(), "You are in the Barn. There are feces everywhere.");
  //Middle Layer
  Room* room1_2 = new Room();
  strcpy(room1_2->getName(), "Security Bunkhouse");
  strcpy(room1_2->getDescription(), "You are in the security bunkhouse. There are a few henchmen sleeping");
  Room* room2_2 = new Room();
  strcpy(room2_2->getName(), "Security Checkpoint");
  strcpy(room2_2->getDescription(), "You are in the security checkpoint.");
  Room* room3_2 = new Room();
  strcpy(room3_2->getName(), "Living Room");
  strcpy(room3_2->getDescription(), "You are in the living room. Nothing much to see here.");
  Room* room4_2 = new Room();
  strcpy(room4_2->getName(), "Greenhouse");
  strcpy(room4_2->getDescription(), "You are in the greenhouse. It is not green...");
  Room* room5_2 = new Room();
  strcpy(room5_2->getName(), "Lighthouse");
  strcpy(room5_2->getDescription(), "You are in the old lighthouse. Don't fall.");
  //Last Layer
  Room* room1_3 = new Room();
  strcpy(room1_3->getName(), "Freezer Room");
  strcpy(room1_3->getDescription(), "It is super cold");
  Room* room2_3 = new Room();
  strcpy(room2_3->getName(), "Illegal Substance Creation Room");
  strcpy(room2_3->getDescription(), "You are in the illegal substance creation room! There are drug making things everywhere. You cover your nose becuase you dont want to breath any of it in.");
  Room* room3_3 = new Room();
  strcpy(room3_3->getName(), "Artillery");
  strcpy(room3_3->getDescription(), "You are in the Artillery. There are hundreds of deadly guns in this room. There is a sudden noise and you sprain your wrist trying to lift it, there goes one escape route");
  Room* room4_3 = new Room();
  strcpy(room4_3->getName(), "Meeting Room");
  strcpy(room4_3->getDescription(), "You are in the meeting room. There are tables with chairs all around. At the end there is a gold plated chair.");
  Room* room5_3 = new Room();
  strcpy(room5_3->getName(), "Entrance");
  strcpy(room5_3->getDescription(), "You are at the entrance but the door is locked. There is a coat hanger with coats and hats on it.");
  //Room Directions
  //First Layer
  room1_1->getExits()->insert(pair<const char*, Room*>("east", room2_1));//goes into the exits vector inside the room and inserts an exit in the desired direction and tells where it leads using a pointer to that room
  room1_1->getExits()->insert(pair<const char*, Room*>("south", room1_2));//repeted below
  room2_1->getExits()->insert(pair<const char*, Room*>("west", room1_1));
  room3_1->getExits()->insert(pair<const char*, Room*>("east", room4_1));
  room3_1->getExits()->insert(pair<const char*, Room*>("south", room3_2));
  room4_1->getExits()->insert(pair<const char*, Room*>("west", room3_1));
  room4_1->getExits()->insert(pair<const char*, Room*>("south", room4_2));
  room4_1->getExits()->insert(pair<const char*, Room*>("east", room5_1));
  room5_1->getExits()->insert(pair<const char*, Room*>("south", room5_2));
  room5_1->getExits()->insert(pair<const char*, Room*>("west", room4_1));
  //Second Layer
  room1_2->getExits()->insert(pair<const char*, Room*>("north", room1_1));
  room1_2->getExits()->insert(pair<const char*, Room*>("east", room2_2));
  room1_2->getExits()->insert(pair<const char*, Room*>("south", room1_3));
  room2_2->getExits()->insert(pair<const char*, Room*>("west", room1_2));
  room2_2->getExits()->insert(pair<const char*, Room*>("east", room3_2));
  room3_2->getExits()->insert(pair<const char*, Room*>("west", room2_2));
  room3_2->getExits()->insert(pair<const char*, Room*>("north", room3_1));
  room4_2->getExits()->insert(pair<const char*, Room*>("north", room4_1));
  room4_2->getExits()->insert(pair<const char*, Room*>("east", room5_2));
  room5_2->getExits()->insert(pair<const char*, Room*>("west", room4_2));
  room5_2->getExits()->insert(pair<const char*, Room*>("north", room5_1));
  //Third Layer
  room1_3->getExits()->insert(pair<const char*, Room*>("north", room1_2));
  room1_3->getExits()->insert(pair<const char*, Room*>("east", room2_3));
  room2_3->getExits()->insert(pair<const char*, Room*>("west", room1_3));
  room2_3->getExits()->insert(pair<const char*, Room*>("east", room3_3));
  room3_3->getExits()->insert(pair<const char*, Room*>("east", room4_3));
  room3_3->getExits()->insert(pair<const char*, Room*>("west", room2_3));
  room4_3->getExits()->insert(pair<const char*, Room*>("west", room3_3));
  room4_3->getExits()->insert(pair<const char*, Room*>("east", room5_3));
  room5_3->getExits()->insert(pair<const char*, Room*>("west", room4_3));
  Player* p = new Player(room1_1);//creating player
  //Items and Locations
  //essential Items - items that need to be picked up to win
  Item* hat = new Item((char*)"Fedora");//new item object with a name "Yellow hat"
  room5_3->addItem(hat);//adds object to room
  Item* toys = new Item((char*)"Rubber Ducky");//repeted below
  room3_1->addItem(toys);
  Item* pumpkin = new Item((char*)"Pumpkin");
  room4_2->addItem(pumpkin);
  Item* snow = new Item((char*)"Snow Cone Machine");
  room2_3->addItem(snow);
  Item* banana = new Item((char*)"Banana");
  room5_1->addItem(banana);
  //Non-essential items
  Item* cocaine = new Item((char*)"Drugs that you are familar with.");
  room1_3->addItem(cocaine);
  Item* maraijuana = new Item((char*)"Drugs that you've only read about.");
  room1_3->addItem(maraijuana);
  Item* heroin = new Item((char*)"THIS DRUG EXISTS?");
  room1_3->addItem(heroin);
  Item* gun = new Item((char*)"Light Gun");
  room3_3->addItem(gun);
  Item* bulb = new Item((char*)"Light Bulb");
  room5_2->addItem(bulb);
  while(running){//main run loop
    cin.get(str, 50);//gets string inputed by user
    cin.clear();
    cin.ignore(10000, '\n');
    running = parser.processCommand(str, p);//if the parser command returns false running becomes false
  }
  return 0;//exits program
}
