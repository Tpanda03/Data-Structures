#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>
#include "game.h"
#include "song.h"
#include "media.h"
#include "movie.h"

using namespace std;

void ADD(vector<Media*>* media) {
  char input[15];
  cout << "What would you like to add? (games, songs, movies)" << endl;
  cin.get(input, 15);
  cin.clear();
  cin.ignore(1000000, '\n');
  if((strcmp(input, "movies")) == 0) {
    Movie* movie = new Movie();

    cout << "Title: ";
    cin.get(movie->getTitle(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Year: ";
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Director: ";
    cin.get(movie->getDirector(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Duration: ";
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Rating: ";
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(1000000, '\n');

    media->push_back(movie);
  }
  else if((strcmp(input, "songs")) == 0) {
    Song* song = new Song();

    cout << "Title: ";
    cin.get(song->getTitle(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Year: ";
    cin >> *song->getYear();
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Artist: ";
    cin.get(song->getArtist(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Duration: ";
    cin >> *song->getDuration();
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Publisher: ";
    cin.get(song->getPublisher(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');

    media->push_back(song);
  }
  else if((strcmp(input, "games")) == 0) {
    Game* game = new Game();
    
    cout << "Title: ";
    cin.get(game->getTitle(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Year: ";
    cin >> *game->getYear();
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Publisher: ";
    cin.get(game->getPublisher(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "Rating: ";
    cin >> *game->getRating();
    cin.clear();
    cin.ignore(1000000, '\n');

    media->push_back(game);
  }
  else {
    cout << "That is not a valid command, try again" << endl;
  }
}

void LOOK(char* title, vector<Media*>* media) {
  vector<Media*>::iterator a;
  for(a = media->begin(); a != media->end(); ++a) {
    if(strcmp(title, (*a)->getTitle()) == 0) {
	cout << endl << "The Title: " << (*a)->getTitle() << endl;
	cout << "The Year: " << *(*a)->getYear() << endl;
	if((*a)->getType() == 0) {
	  cout << "Director: " << dynamic_cast<Movie*>(*a)->getDirector() << endl;
	  cout << "Duration: " << dynamic_cast<Movie*>(*a)->getDuration() << endl;
	  cout << "Rating: " << dynamic_cast<Movie*>(*a)->getRating() << endl;
 	}
	else if((*a)->getType() == 1) {
	  cout << "Publisher: " << dynamic_cast<Game*>(*a)->getPublisher() << endl;
	  cout << "Rating: " << dynamic_cast<Game*>(*a)->getRating() << endl;
	}
	else if((*a)->getType() == 2) {
	  cout << "Artist: " << dynamic_cast<Song*>(*a)->getArtist() << endl;
	  cout << "Duration: " << dynamic_cast<Song*>(*a)->getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Song*>(*a)->getPublisher() << endl;
	}
      }
  }
}
void DELETE(char* title, vector<Media*>* media) {
  char input[10];
  vector<Media*>::iterator b;
  for(b = media->begin(); b != media->end(); ++b) {
    if(strcmp(title, (*b)->getTitle()) == 0) {
      cout << endl << "The Title: " << (*b)->getTitle() << endl;
      cout << "The Year: " << *(*b)->getYear() << endl;
      	if((*b)->getType() == 0) {
	  cout << "Director: " << dynamic_cast<Movie*>(*b)->getDirector() << endl;
	  cout << "Duration: " << dynamic_cast<Movie*>(*b)->getDuration() << endl;
	  cout << "Rating: " << dynamic_cast<Movie*>(*b)->getRating() << endl;
 	}
	else if((*b)->getType() == 1) {
	  cout << "Publisher: " << dynamic_cast<Game*>(*b)->getPublisher() << endl;
	  cout << "Rating: " << dynamic_cast<Game*>(*b)->getRating() << endl;
	}
	else if((*b)->getType() == 2) {
	  cout << "Artist: " << dynamic_cast<Song*>(*b)->getArtist() << endl;
	  cout << "Duration: " << dynamic_cast<Song*>(*b)->getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Song*>(*b)->getPublisher() << endl;
	}
	cout << "Are you sure you want to delete this? ('y' for yes and 'n' for no): ";
	cin.get(input, 10);
	cin.clear();
	cin.ignore(1000000, '\n');

	if(strcmp(input, "y") == 0) {
	  delete *b;
	  b = media->erase(b);
	  return;
	}
      }
    }
  }

 void LOOK(int year, vector<Media*>* media) {
     vector<Media*>::iterator a;
  for(a = media->begin(); a != media->end(); ++a) {
    if(year == *(*a)->getYear()) {
	cout << endl << "The Title: " << (*a)->getTitle() << endl;
	cout << "The Year: " << *(*a)->getYear() << endl;
	if((*a)->getType() == 0) {
	  cout << "Director: " << dynamic_cast<Movie*>(*a)->getDirector() << endl;
	  cout << "Duration: " << dynamic_cast<Movie*>(*a)->getDuration() << endl;
	  cout << "Rating: " << dynamic_cast<Movie*>(*a)->getRating() << endl;
 	}
	else if((*a)->getType() == 1) {
	  cout << "Publisher: " << dynamic_cast<Game*>(*a)->getPublisher() << endl;
	  cout << "Rating: " << dynamic_cast<Game*>(*a)->getRating() << endl;
	}
	else if((*a)->getType() == 2) {
	  cout << "Artist: " << dynamic_cast<Song*>(*a)->getArtist() << endl;
	  cout << "Duration: " << dynamic_cast<Song*>(*a)->getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Song*>(*a)->getPublisher() << endl;
	}
      }
    }
 }

 void DELETE(int year, vector<Media*>* media) {
     char input[10];
  vector<Media*>::iterator b;
  for(b = media->begin(); b != media->end(); ++b) {
    if(year == *(*b)->getYear()) {
      cout << endl << "The Title: " << (*b)->getTitle() << endl;
      cout << "The Year: " << *(*b)->getYear() << endl;
      	if((*b)->getType() == 0) {
	  cout << "Director: " << dynamic_cast<Movie*>(*b)->getDirector() << endl;
	  cout << "Duration: " << dynamic_cast<Movie*>(*b)->getDuration() << endl;
	  cout << "Rating: " << dynamic_cast<Movie*>(*b)->getRating() << endl;
 	}
	else if((*b)->getType() == 1) {
	  cout << "Publisher: " << dynamic_cast<Game*>(*b)->getPublisher() << endl;
	  cout << "Rating: " << dynamic_cast<Game*>(*b)->getRating() << endl;
	}
	else if((*b)->getType() == 2) {
	  cout << "Artist: " << dynamic_cast<Song*>(*b)->getArtist() << endl;
	  cout << "Duration: " << dynamic_cast<Song*>(*b)->getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Song*>(*b)->getPublisher() << endl;
	}
	cout << "Are you sure you want to delete this? ('y' for yes and 'n' for no): ";
	cin.get(input, 10);
	cin.clear();
	cin.ignore(1000000, '\n');

	if(strcmp(input, "y") == 0) {
	  delete *b;
	  b = media->erase(b);
	  return;
	}
      }
    }
 }

 int main() {
   bool quit = false;
   vector<Media*> mediaArr;
   char input[10];
   char secondInput[100];
   int thirdInput;
   while(quit == false) {
     cout << "What task do you want to perform? (add, look, delete, quit)" << endl;
     cin.get(input, 10);
     cin.clear();
     cin.ignore(1000000, '\n');
     if((strcmp(input, "add")) == 0) {
       ADD(&mediaArr);
     }
     else if((strcmp(input, "look")) == 0) {
       cout << "Do you want to search by year or title?" << endl;
       cin.get(input, 10);
       cin.clear();
       cin.ignore(1000000, '\n');
       if(strcmp(input, "year") == 0) {
	   cout << "Which Year? " << endl;
	   cin >> thirdInput;
	   cin.clear();
	   cin.ignore(1000000, '\n');
	   LOOK(thirdInput, &mediaArr);
	   
       }
       else if(strcmp(input, "title") == 0) {
	   cout << "What Title? " << endl;
	   cin.get(secondInput, 10);
	   cin.clear();
	   cin.ignore(1000000, '\n');
	   LOOK(secondInput, &mediaArr);
       }
       else {
	 cout << "That was not what I asked for" << endl;
       }
     }
     else if((strcmp(input, "delete")) == 0) {
       cout << "Do you want to delete by year or title?" << endl;
       cin.get(input, 10);
       cin.clear();
       cin.ignore(1000000, '\n');
       if(strcmp(input, "year") == 0) {
	   cout << "Which Year? " << endl;
	   cin >> thirdInput;
	   cin.clear();
	   cin.ignore(1000000, '\n');
	   DELETE(thirdInput, &mediaArr);
	   
       }
       else if(strcmp(input, "title") == 0) {
	   cout << "What Title? " << endl;
	   cin.get(secondInput, 10);
	   cin.clear();
	   cin.ignore(1000000, '\n');
	   DELETE(secondInput, &mediaArr);
       }
       else {
	 cout << "That was not what I asked for" << endl;
       }       
     }
     else if((strcmp(input, "quit")) == 0) {
       cout << "See ya!" << endl;
       quit = true;
     }
     else {
       cout << "that was an invalid input" << endl;
     }
   }
 }
