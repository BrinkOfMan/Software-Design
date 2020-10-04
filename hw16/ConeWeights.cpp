#include<iostream>
using namespace std;

class ConeWeights {
    int num_cones;
    float *data;
public:
    
    ConeWeights(int n) { num_cones = n; data = new float[num_cones]; }
    
    ~ConeWeights() { cout << "bye!" << endl; delete [] data; }

    void assign_cone_weight(int i, float w) { data[i] = w; }

    void multBy3(){
        for(int i = 0; i < num_cones; ++i)
            if(data[i]) data[i] *= 3;
        }

    void add1() {
        float *temp_cones = new float[num_cones];
        for(int i = 0; i < num_cones; ++i) {temp_cones[i] = data[i];}

        delete [] data;
        num_cones += 1;
        data = new float[num_cones];

        int i;
        for(i = 0; i < num_cones; ++i){
            data[i] = temp_cones[i];
        }
        
        data[i] = 0;
        delete [] temp_cones;
    }
        
    void display() { cout << "num_cones " << num_cones << endl;}
};

int main()
{
    ConeWeights cs{251}; // constructor is automatically called here
    cs.assign_cone_weight(0, 125.5);
    cs.multBy3();
    cs.add1();
    cs.display();
    // invisible feature:  the destructor is automatically called here!
}
