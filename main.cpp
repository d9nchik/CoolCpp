#include <map>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void show_pair(const T &iterator) {
    cout << "[" << iterator->first << ": " << iterator->second << "]";
}

template<typename T>
void show_map(const T &map) {
    cout << "[ ";
    auto iterator = map.cbegin();
    for (int i = 0; i < map.size() - 1; ++i) {
        show_pair(iterator++);
        cout << ",";
    }

    if (!map.empty())
        show_pair(iterator);
    cout << "]";
}

int main() {
    map<string, int> myMap;
    cout << "Testing map:" << endl;
    myMap.insert(make_pair("Vova", 17));
    myMap.insert(make_pair("Andriy", 4));
    myMap.insert(make_pair("Natasha", 5));
    cout << "Before adding duplicated value 'Andriy'" << endl;
    show_map(myMap);
    cout << endl;
    myMap.insert(make_pair("Andriy", 7));
    cout << "After adding duplicated value 'Andriy'" << endl;
    show_map(myMap);
    cout << endl;

    multimap<string, int> myMultimap;
    cout << "Testing map:" << endl;
    myMultimap.insert(make_pair("Vova", 17));
    myMultimap.insert(make_pair("Andriy", 4));
    myMultimap.insert(make_pair("Natasha", 5));
    cout << "Before adding duplicated value 'Andriy'" << endl;
    show_map(myMultimap);
    cout << endl;
    myMultimap.insert(make_pair("Andriy", 7));
    cout << "After adding duplicated value 'Andriy'" << endl;
    show_map(myMultimap);
    cout << endl;

    return 0;
}