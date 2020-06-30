#include <unordered_map>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct WordProperty {
    string word;
    bool isLatinBase;
};

class FPredicate {
    bool operator()(const WordProperty &wp1, const WordProperty &wp2) const {
        return wp1.word < wp2.word;
    }
};

int main() {
    return 0;
}