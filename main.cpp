#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class SortHelper {
public:
    int operator()(const T &element1, const T &element2) {
        return element1 < element2;
    }
};

template<typename T>
class ShowData {
public:
    void operator()(const T &element) const {
        cout << element << ", ";
    }
};

int main() {
    vector<double> doubles = {3.2, 5.1, 4.7, 8.2, 2.0};
    sort(doubles.begin(), doubles.end(), SortHelper<double>());
    cout<<"Sorting in ascending order:" << endl;
    for_each(doubles.cbegin(), doubles.cend(), ShowData<double>());
    return 0;
}