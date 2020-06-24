#include <iostream>

using namespace std;

template<typename T>
void exchange(T &a, T &b);

int main() {
    int a = 5;
    int b = 7;

    cout << "a = " << a << endl << "b = " << b << endl;
    exchange(a, b);

    cout << "a = " << a << endl << "b = " << b << endl;
    return 0;
}

template<typename T>
void exchange(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}