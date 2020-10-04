#include <iostream>
using namespace std;

int main(int argc, char **argv){
    
    unsigned char num_messages = 0;

    if(argc != 2){
        cerr << "Usage: ./chat1 <username>\n"; 
        return 0;
    }

    else {
        while(1){
            char message[80];
            cout << static_cast<int>(num_messages) << endl;
            cout << argv[1] << "> ";
            cin.getline(message, 80);
            if(message[0] != 0) { ++num_messages; }
        }
        
    }
}