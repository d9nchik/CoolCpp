#include <iostream>

using namespace std;

template<typename T>
T multiply(const T &a, const T &b);

int main() {
    cout << multiply<double>(5 - 1.5, 3 - 1) << endl;
    return 0;
}

template<typename T>
T multiply(const T &a, const T &b) {
    return a * b;
}