#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> ints = {10, 20};
    auto first = ints.cbegin();
    auto second = --ints.cend();
    ints.insert(++ints.cbegin(), 15);
    cout << "First: " << *first << "; Second: " << *second << endl;

    return 0;
}