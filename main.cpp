#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    cout << "Enter a sentence: ";
    int numberOfVowels = 0;
    const string vowels = "aeiou";
    string userSentence;
    getline(cin, userSentence);

    transform(userSentence.begin(), userSentence.end(), userSentence.begin(), ::tolower);

    for (char vowel : vowels) {
        auto charPos = userSentence.find(vowel);
        while (charPos != string::npos) {
            numberOfVowels++;
            charPos = userSentence.find(vowel, charPos + 1);
        }
    }

    cout << "Found " << numberOfVowels << " vowels";

    return 0;
}
