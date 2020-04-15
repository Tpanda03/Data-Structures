#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  cout << "Type a word or a phrase and I will check if it is a palindrome or not!" << endl;
  //initialize variables
  char a[80];
  char b[80];
  char c[80];
  int count = 0;
  for (int i = 0;i < 79;i++) {
    a[i] = 0;
    b[i] = 0;
    c[i] = 0;
  }
  cin.get(a,80);
  cin.get();
  for (int i = 0; i < 79; i++) {//for the first 80 characters
    if (a[i] >= 97 && a[i] <= 122) {//remove all spaces and punctuation and copy to b array
      b[count] = a[i];
      count++;
    }
    else if (a[i] >= 65 && a[i] <= 90) {// do the same for lowercase letters
      b[count] = a[i] + 32;
      count++;
    }
  }
  count = 0;
  for (int i = 79; i >= 0; i--) { //reverse string b and copy to c
    if (b[i] != 0) {
      c[count] = b[i];
      count++;
    }
  }
  if (strcmp(b,c) == 0) {//compare reverse string to straight string, if same it equals 0
    cout << "This is a Palindrome" << endl;
  }
  else {
    cout << "This is not a Palindrome" << endl;
  }
}
