#include <iostream>
#include <string.h>

using namespace std;

void clear(char* Ptr[3][3]);//method to clear the board
void draw(char* Ptr[3][3]);//method to draw the board
bool win(char* Ptr[3][3], char player);//method to check for a win condition
bool tie(char* Ptr[3][3]);//method to check if the game ended in a tie
int xDubs = 0;
int oDubs = 0;

int main()
{
  char board[3][3];
  char* boardPtr[3][3];
  char input[2];
  char player = 'o';//player piece
  char playAgain = 'y';//play again 
  bool attempts = true;

  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      boardPtr[x][y] = &board[x][y];
    }
  }
  while(playAgain == 'y') {//run the game through once
    cout << "Score X wins: " << xDubs << endl;
    cout << "Score O wins: " << oDubs << endl;
    //start with a empty board
    clear(boardPtr);
    draw(boardPtr);
    player = 'o';
    while(!win(boardPtr, player) && !tie(boardPtr)){
      if(player == 'x') {
	player = 'o';
      }
      else {
	player = 'x';
      }
      do {
	if (attempts == true){
	  cout << "place your piece on the board." << endl;
	}
	cin.get(input, 3);
	cin.clear();
	cin.ignore(1000000, '\n');
	attempts = false;
      }while (!(input[0] == '1' || input[0] == '2' || input[0] == '3')
	      || !(input[1] == 'a' || input[1] == 'b' || input[1] == 'c')
	      || !(board[(int)input[1] - 'a'][(int)input[0] - '1'] == ' '));//while piece is placed in a valid spot
      attempts = true;
      board[(int)input[1] - 'a'][(int)input[0] - '1'] = player;
      draw(boardPtr);
    }
    if(tie(boardPtr)){//in the case tie is an event
      cout << "This match ends in a tie" << endl;
    }
    else {
      cout << "Congrats " << player << " on winning this match of tic tac toe!" << endl;//when someone wins
      if(player == 'x') {
	xDubs++;
      }
      else{
	oDubs++;
      }
    }
    cout << "Do you want to play again?" << endl;//i never want to do tic tac toe again.
    cin >> playAgain;
    cin.clear();
    cin.ignore(1000000, '\n');
  }
}
void clear(char* Ptr[3][3]){//the method for clearing the board
  for(int x = 0; x < 3; x++) {
    for(int y = 0; y < 3; y++) {
      *Ptr[x][y] = ' ';
    }
  }
}

void draw(char* Ptr[3][3]) {//method to draw the board
  cout << " 1 2 3" << endl;
  cout << 'a';
  for( int i = 0; i < 3; i++) {
    cout << ' ' << *Ptr[0][i];
  }
  cout << endl;

  cout << 'b';
  for(int i = 0; i < 3; i++) {
    cout << ' ' << *Ptr[1][i];
  }
  cout << endl;

  cout << 'c';
  for(int i = 0; i < 3; i++) {
    cout << ' ' << *Ptr[2][i];
  }
  cout << endl;
}

bool tie(char* Ptr[3][3]){//check tie
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      if(*Ptr[x][y] == ' '){
	return false;
      }
    }
  }
  return true;
}

bool win(char* Ptr[3][3], char player){//check win
  for(int i = 0; i < 3; i++){
    if(*Ptr[0][i] == player && *Ptr[1][i] == player && *Ptr[2][i] == player){
      return true;
    }
    if(*Ptr[i][0] == player && *Ptr[i][1] == player && *Ptr[1][2] == player){
      return true;
    }
  }
  if(*Ptr[0][0] == player && *Ptr[1][1] == player && *Ptr[2][2] == player){
    return true;
  }
  if(*Ptr[2][0] == player && *Ptr[1][1] == player && *Ptr[0][2] == player){
    return true;
  }
  return false;
}

