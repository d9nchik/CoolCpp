#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class ShowData {
private:
    unsigned int counter = 0;
public:
    void operator()(const T &element) {
        cout << element << ", ";
        ++counter;
    }

    unsigned int getCounter() const {
        return counter;
    }

};

int main() {
    vector<double> doubles = {3.2, 5.1, 4.7, 8.2, 2.0};
    ShowData<double> showData = for_each(doubles.cbegin(), doubles.cend(), ShowData<double>());
    cout << endl;
    cout << "ShowData() has been called " << showData.getCounter() << " times.";
    return 0;
}