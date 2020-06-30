#include <unordered_map>
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
    unordered_multimap<string, string> telephoneDirectory;
    return 0;
}