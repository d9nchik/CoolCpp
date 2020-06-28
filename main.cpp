#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
void show(const T &list);

int main() {
    list<string> lisNumbers = {"Danila", "Nikita", "Anton", "Stephan"};
    cout << "Initial list:" << endl;
    show(lisNumbers);

    lisNumbers.reverse();
    cout << "List after reversing:" << endl;
    show(lisNumbers);

    lisNumbers.sort();
    cout << "List after sorting:" << endl;
    show(lisNumbers);

    return 0;
}

template<typename T>
void show(const T &list) {
    cout << "[ ";
    for (auto iterator = list.cbegin(); iterator != list.cend(); ++iterator)
        cout << *iterator << " ";
    cout << "]" << endl;
}