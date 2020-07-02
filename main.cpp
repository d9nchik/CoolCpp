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
    cout << "Before sorting:" << endl;
    for_each(doubles.cbegin(), doubles.cend(), ShowData<double>());
    cout << endl;
    cout << "Sorting in ascending order:" << endl;
    sort(doubles.begin(), doubles.end(), [](const auto &e1, const auto &e2) -> bool { return e1 > e2; });
    for_each(doubles.cbegin(), doubles.cend(), ShowData<double>());
    return 0;
}