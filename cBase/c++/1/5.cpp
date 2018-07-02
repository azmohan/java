#include <iostream>
using namespace std;

void modifyRef(int & a) {
    a = 100;
}

void modifyVal(int a) {
    a = 200;
}
int main() {
    int ival = 1024;
    int & refVal = ival;
    cout << "ival:" << ival << ",refVal:" << refVal << endl;
    refVal = 2048;
    cout << "ival:" << ival << ",refVal:" << refVal << endl;
    modifyRef(refVal);
    cout << "ival:" << ival << ",refVal:" << refVal << endl;
    modifyVal(ival);
    cout << "ival:" << ival << ",refVal:" << refVal << endl;
    modifyVal(refVal);
    cout << "ival:" << ival << ",refVal:" << refVal << endl;
    ival = 20;
    cout << "ival:" << ival << ",refVal:" << refVal << endl;
    modifyRef(ival);
    cout << "ival:" << ival << ",refVal:" << refVal << endl;

    int & refVal2 = refVal;

    int i = 1024,i2 = 2048;
    int &r = i,r2 =i2;
    int i3 = 1024,&ri = i3;
    int &r3 = i3,&r4 = i2;
    return 0;
}
