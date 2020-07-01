#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class showData {
public:
    void operator()(const T &element) {
        cout << element << ", ";
    }

};

int main() {
    vector<double> doubles ={3.2, 5.1, 4.7, 8.2, 2.0};
    for_each(doubles.cbegin(), doubles.cend(), showData<double>());

    return 0;
}