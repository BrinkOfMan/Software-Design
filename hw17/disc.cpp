#include<iostream>
using namespace std;

class UltimateFrisbee {
    int size;
    float *data;
public:
    UltimateFrisbee() { size = 0; data = 0; }
    UltimateFrisbee(int s) { size = s; data = new float[size]; }

    UltimateFrisbee(const UltimateFrisbee &b) {
        
        if(data) {
            cout << "Making a copy!\n";
            size = b.size;
            data = new float[size];
            for(int i = 0; i < size; ++i) data[i] = b.data[i];
        }

        else cout << "No copy made.\n";
    
    }

    ~UltimateFrisbee() { cout << "bye!" << endl; if (data) delete [] data; }

    void display()
        { cout << "size " << size << endl;}
};

int main()
{
    UltimateFrisbee g1, g2(3);

    g1.display();
    g2.display();
}
