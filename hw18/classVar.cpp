#include<iostream>
using namespace std;

class ConeWeights {
    int num_cones;
    float *data;
public:

    static int num_created;

    // constructors
    ConeWeights(int n) { num_cones = n; data = new float[num_cones]; ++num_created;}
    ConeWeights(const ConeWeights &c) {
        num_cones = c.num_cones;
        data = new float[num_cones];
        for (int i = 0; i < num_cones; ++i) data[i] = c.data[i];
        ++num_created;
    }
    // destructor
    ~ConeWeights() { cout << "bye!" << endl; delete [] data; }

    ConeWeights &operator=(const ConeWeights &c) { // version 4
    num_cones = c.num_cones;
    delete [] data;
    data = new float[c.num_cones];
    for (int i = 0; i < c.num_cones; ++i) data[i] = c.data[i];
    return *this;
  }




    void assign_cone_weight(int i, float w) { data[i] = w; }
    void display()
        { cout << "num_cones " << num_cones << endl;}
};

int ConeWeights::num_created = 0;

int main()
{
    ConeWeights c1{251}, c2{252};
    ConeWeights c3{253};
    c3 = c2.operator=(c1);
    cout << "Running display() for c1, c2, and c3:\n";
    c1.display();
    c2.display();
    c3.display();

    cout << "There have been " << c1.num_created << " ConeWeights objects created" << endl;
}
