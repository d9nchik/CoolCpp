#include <iostream>

using namespace std;

template<typename T>
void display(T &val) {
    cout << val;
}

template<typename T, typename...Rest>
void display(T &val1, Rest...val);

int main() {
    int number = 1;
    display(number, "Hi,", "Bob", number);
}

template<typename T, typename...Rest>
void display(T &val1, Rest...val) {
    cout << val1 << " ";
    display(val...);
}