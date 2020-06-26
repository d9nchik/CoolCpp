#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    const string str = "Good day String! Today is beautiful!";
    auto posChar = str.find('a');
    while (posChar != string::npos) {
        cout << "\'a\' found at position: " << posChar << endl;
        posChar = str.find('a', posChar + 1);
    }
    return 0;
}
