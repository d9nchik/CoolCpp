#include <iostream>
#include <vector>
#include <algorithm>

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
}