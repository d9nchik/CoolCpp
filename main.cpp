#include <set>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

template<typename T>
void show(const T &elements) {
    cout << "[";
    for (auto start = elements.cbegin(); start != elements.cend(); ++start)
        cout << *start << ", ";
    cout << "]" << endl;
}

int main() {
    multiset<int> multiInt = {-1, 3, 8, 100, 1, 0};
    cout << "Initial capacity of multiset:" << endl;
    show(multiInt);
    multiInt.insert(3);
    cout << "After inserting'3':" << endl;
    show(multiInt);

    cout << endl;

    set<int> setInt = {-1, 3, 8, 100, 1, 0};
    cout << "Initial capacity of set:" << endl;
    show(setInt);
    setInt.insert(3);
    cout << "After inserting'3':" << endl;
    show(setInt);

    return 0;
}