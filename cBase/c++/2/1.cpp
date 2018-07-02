#include <iostream>
using namespace std;

class T {
    public :
        T() {cout << "constructor" << endl;}
        ~T() {cout << "destructor" << endl;}
};

int main () {
    const int NUM = 3;
    T * p1 = new T[NUM];
    cout << hex << p1 << endl;
    cout << hex << (p1 + 1) << endl;
    cout << hex << (p1 + 2) << endl;
    cout << hex << (p1 + 3) << endl;
    delete [] p1;
    return 0;
}
