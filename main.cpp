#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template<typename T>
class ShowData {
public:
    void operator()(const T &element) const {
        cout << element << ", ";
    }
};

class CompareString {
    bool operator()(const string &s1, const string &s2) {
        string copyS1(s1);
        string copyS2(s2);
        transform(copyS1.begin(), copyS1.end(), copyS1.begin(), ::tolower);
        transform(copyS2.begin(), copyS2.end(), copyS2.begin(), ::tolower);
        return copyS1 < copyS2;
    }
};

int main() {
    vector<int> vectorInt = {1, 2, 3, 4, 5};
    cout << "Before inserting:" << endl;
    for_each(vectorInt.cbegin(), vectorInt.cend(), ShowData<int>());
    int previousSize = vectorInt.size();
    cout << endl;
    list<int> listInt = {6, 7, 8, 9};
    vectorInt.resize(previousSize + listInt.size());
    copy(listInt.cbegin(), listInt.cend(), (vectorInt.begin() + previousSize));

    cout << "After inserting:" << endl;
    for_each(vectorInt.cbegin(), vectorInt.cend(), ShowData<int>());
    return 0;
}