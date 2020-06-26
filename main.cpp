#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    cout << "Enter a word: ";
    string userWord;
    cin >> userWord;
    transform(userWord.begin(), userWord.end(), userWord.begin(), ::tolower);
    string copyOfWord = userWord;
    reverse(copyOfWord.begin(), copyOfWord.end());
    cout << "Word is ";
    if (userWord != copyOfWord)
        cout << "not ";
    cout << "palindrome" << endl;
    return 0;
}
