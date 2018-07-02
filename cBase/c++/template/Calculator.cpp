using namespace std;
#include <iostream>
#include <string>
template <typename T>
class Calculator {
    T mVar;
    virtual T add (T a,T b) {
        return a + b;
    }

    T minus(T a, T b) {
        return a - b;
    }
};

int main() {
    Calulator<int> c;
    cout << c.add(2,3) << endl;
    cout << c.minus(9,5) << endl;

    string s1 = "Hello" ;
    string s2 = " World";
    Calculator<string> d;
    cout << d.add(s1,s2) << endl;
//    cout << d.minus(s1,s2) << endl;
    return 0;
}

