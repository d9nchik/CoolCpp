#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    cout << "Enter a sentence: ";
    string userSentence;
    getline(cin, userSentence);

    transform(userSentence.begin(), userSentence.end(), userSentence.begin(), ::toupper);


    cout << "Converted every alternate character of a string into uppercase: " << endl;
    cout << userSentence << endl;

    return 0;
}
