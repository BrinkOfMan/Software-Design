#include<iostream>
using namespace std;

class Note {
  char *sender;
  char *message;

public:
  Note() {  // this constructor is called a default constructor
    sender = new char[3];
    sender[0] = 'A';  sender[1] = 'B';  sender[2] = 0;
    message = new char[3];
    message[0] = 'h';  message[1] = 'i';  message[2] = 0;
  }

  Note(const Note &b) {
    cout << "Making a copy!\n";
    sender = new char [3];
    sender[0] = b.sender[0]; sender[1] = b.sender[1]; sender[2] = b.sender[2];
    message = new char [3];
    message[0] = b.message[0]; message[1] = b.message[1]; message[2] = b.message[2];

  }

  ~Note() { delete [] sender; delete [] message; }

  void display(ostream &os) {
    os << "sender: " << sender << " ";
    os << "message: " << message << "\n";
  }
};

void f(Note d) {
  d.display(cout);
}

int main() {
  Note n1, n2;
  cout << "Sending n1 to function f\n";
  f(n1);

  cout << "\nCreating a copy of n2\n";
  Note n2copy{n2};
}
