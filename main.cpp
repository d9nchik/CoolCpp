#include <set>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Dictionary {
    string word;
    string meaning;
public:
    explicit Dictionary(string word, string meaning="") : word(std::move(word)), meaning(std::move(meaning)) {}

    const string &getWord() const {
        return word;
    }

    const string &getMeaning() const {
        return meaning;
    }

    bool operator<(const Dictionary &rhs) const {
        return word < rhs.word;
    }

    bool operator==(const Dictionary &rhs) const {
        return word == rhs.word;
    }

    friend ostream &operator<<(ostream &os, const Dictionary &dictionary) {
        os << "word: " << dictionary.word << " meaning: " << dictionary.meaning;
        return os;
    }
};

int main() {
    multiset<Dictionary> multiset;
    Dictionary book("book", "A book is a medium for recording information in"
                            " the form of writing or images.");
    Dictionary phone("phone", "A telephone is a telecommunications device that permits two or more users "
                              "to conduct a conversation when they are too far apart to be heard directly.");
    Dictionary language("language", "A language is a structured system of communication.");

    multiset.insert(book);
    multiset.insert(phone);
    multiset.insert(language);

    cout << "Enter a word you would like to learn meaning: ";
    string word;
    getline(cin, word);
    auto foundWord = multiset.find(Dictionary(word));
    if (foundWord != multiset.cend())
        cout << *foundWord << endl;
    else
        cout << "Word not found!" << endl;

    return 0;
}