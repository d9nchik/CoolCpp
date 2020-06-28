#include <iostream>
#include <list>

using namespace std;

template<typename T>
void show(const T &elements);

int DisplayOptions() {
    cout << "What would you like to do?" << endl;
    cout << "Select 1: To enter an integer" << endl;
    cout << "Select 2: To display the vector" << endl << "> ";
    cout << "Select 3: To quit!" << endl << "> ";
    int ch;
    cin >> ch;
    return ch;
}

int main() {
    list<int> elements;
    int chUserChoice;
    while ((chUserChoice = DisplayOptions()) != 3) {
        switch (chUserChoice) {
            case 1: {
                cout << "Please enter an integer to be inserted: ";
                int nDataInput = 0;
                cin >> nDataInput;
                elements.push_front(nDataInput);
                break;
            }
            case 2:
                cout << "The contents of the vector are: ";
                show(elements);
                cout << endl;
                break;
            default:
                cout << "Incorrect choice" << endl;
        }
    }
    return 0;
}

template<typename T>
void show(const T &elements) {
    cout << "[";
    for (auto iterator = elements.cbegin(); iterator != elements.cend(); ++iterator)
        cout << *iterator << " ";
    cout << "]" << endl;
}