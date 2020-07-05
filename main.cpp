#include <iostream>
#include <stack>
#include <bitset>

using namespace std;

int main() {
    bitset<4> firstBitset(9);
    cout << "First bitset number: " << firstBitset << endl;
    bitset<4> secondBitset(2);
    cout << "Seconds bits: " << secondBitset << endl;

    bitset<4> resultBitset(firstBitset.to_ulong() + secondBitset.to_ulong());
    cout << "Result of flip: " << resultBitset.flip() << endl;

    return 0;
}