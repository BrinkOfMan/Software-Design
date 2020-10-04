#include<iostream>
using namespace std;

int main(int argc, char **argv) {
  cout << "The program name is " << argv[0] << "\n";
  cout << "You typed in " << (argc-1) << " arguments:\n";
  for (int i = 1; i < argc; ++i) {
    cout << "\t" << argv[i] << "\n";
  }
}
