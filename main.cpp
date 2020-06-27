#include <iostream>
#include <deque>

using namespace std;

template<typename T>
void show(deque<T> elements);

int main() {
    deque<string> stringDeque = {"Hello"s, "Containers are cool!"s, "C++ is evolving"s};
    show(stringDeque);
    return 0;
}

template<typename T>
void show(deque<T> elements) {
    for (int i = 0; i < elements.size(); ++i)
        cout << elements[i] << endl;
}