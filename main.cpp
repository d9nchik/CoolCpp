#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Jar {
    double radius, height;
    string strOut;
public:
    explicit Jar(double radius = 0, double height = 0) : radius(radius), height(height) {
        stringstream os;
        os << "Radius: " << radius << "; Height: " << height << endl;
        strOut = os.str();
    }

    operator const char *() const {
        return strOut.c_str();
    }
};

enum Variants {
    enter, showIndex, showAll, exitOf
};

int getVariant();

template<typename T>
void show(const vector<T> &elements);


int main() {
    vector<Jar> jars;
    while (true) {
        switch (getVariant()) {
            case enter: {
                cout << "Enter radius of jar: ";
                double radius;
                cin >> radius;
                cout << "Enter height of jar: ";
                double height;
                cin >> height;
                Jar jar(radius, height);
                jars.push_back(jar);
                break;
            }
            case showIndex:
                cout << "Enter index: ";
                int index;
                cin >> index;
                if (index >= 0 && index < jars.size())
                    cout << "jars[ " << index << " ] = " << jars[index];
                else
                    cout << "Incorrect index" << endl;
                break;
            case showAll:
                cout << "All elements:" << endl;
                show(jars);
                break;
            case exitOf:
                exit(0);
            default:
                cout << "Incorrect choice!" << endl;
        }
    }

    return 0;
}

int getVariant() {
    cout << "If you want add Jar press - " << Variants::enter << endl;
    cout << "If you want show index of Jar press - " << Variants::showIndex << endl;
    cout << "If you want show all of Jar`s press - " << Variants::showAll << endl;
    cout << "If you want exit press - " << Variants::exitOf << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

template<typename T>
void show(const vector<T> &elements) {
    for (int i = 0; i < elements.size(); ++i)
        cout << ' ' << elements[i] << ' ';
}