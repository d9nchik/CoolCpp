#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
void show(const T &list);

int main() {
    vector<int> numbers = {23, 76, 12, 34, 1, 0};
    list<int> lisNumbers = {25, 40};
    lisNumbers.insert(lisNumbers.begin(), numbers.cbegin(), numbers.cend());
    show(lisNumbers);

    return 0;
}

template<typename T>
void show(const T &list) {
    for (auto iterator = list.cbegin(); iterator != list.cend(); ++iterator)
        cout << *iterator << " ";
    cout << endl;
}