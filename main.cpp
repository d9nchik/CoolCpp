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

int main() {
    vector<double> doubles = {3.2, 5.1, 4.7, 8.2, 2.0};
    cout << "Before modifying:" << endl;
    for_each(doubles.cbegin(), doubles.cend(), ShowData<double>());
    cout << endl;
    cout << "Enter value you would like to add to every element of sequence: ";
    double value;
    cin >> value;
    for_each(doubles.begin(), doubles.end(), [value](auto &e) { e += value; });
    for_each(doubles.cbegin(), doubles.cend(), ShowData<double>());
    return 0;
}