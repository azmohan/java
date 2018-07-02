using namespace std;
#include <iostream>
#include <string>
template <typename T>
T add(T a,T b) {
    return a + b;
}

int main() {
    string s1 = "Hello";
    string s2 = " World";

    cout << add(12,13) << endl;
    cout << add(s1,s2) << endl;
    return 0;
}
