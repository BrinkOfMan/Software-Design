#include<iostream>
using namespace std;

int main() {
  char user_input[20];

  bool first_time = true;
  while(1) {
    if (first_time) {
      cout << "What is your name? (less than 20 characters) ";
    }
    if (!first_time) {
      cout << "Ok, " << user_input << "\n";
    }
    cin.getline(user_input, 20);
    first_time = false;
  }
}
