#include <iostream>

using namespace std;

template<typename T1, typename T2>
class DuoArray {
    const static int SIZE_OF_ARRAY = 10;
    T1 *firstArray;
    T2 *secondArray;
public:
    DuoArray() {
        firstArray = new T1[SIZE_OF_ARRAY];
        secondArray = new T2[SIZE_OF_ARRAY];
    }

    DuoArray(const DuoArray<T1, T2> &srcArray) {
        firstArray = new T1[SIZE_OF_ARRAY];
        secondArray = new T2[SIZE_OF_ARRAY];
        for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
            firstArray[i] = srcArray.firstArray[i];
            secondArray[i] = srcArray.secondArray[i];
        }
    }

    DuoArray &operator=(const DuoArray<T1, T2> &srcArray) {
        if (this != srcArray && srcArray.firstArray != nullptr)
            for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
                firstArray[i] = srcArray.firstArray[i];
                secondArray[i] = srcArray.secondArray[i];
            }
        return *this;
    }

    DuoArray &operator=(DuoArray<T1, T2> &&srcArray) noexcept {
        if (firstArray != nullptr && this != srcArray) {
            delete[] firstArray;
            delete[] secondArray;
            firstArray = srcArray.firstArray;
            srcArray.firstArray = nullptr;
            secondArray = srcArray.secondArray;
            srcArray.secondArray = nullptr;
        }
        return *this;
    }

    DuoArray(DuoArray<T1, T2> &&srcArray) noexcept {
        if (srcArray.firstArray != nullptr) {
            firstArray = srcArray.firstArray;
            srcArray.firstArray = nullptr;
            secondArray = srcArray.secondArray;
            srcArray.secondArray = nullptr;
        }
    }


    T1 *getFirstArray() const {
        return firstArray;
    }

    T2 *getSecondArray() const {
        return secondArray;
    }

    virtual ~DuoArray() {
        delete[] firstArray;
        delete[] secondArray;
    }
};

int main() {
    auto duoArray = new DuoArray<int, string>;

    duoArray->getFirstArray()[1] = 5;
    duoArray->getSecondArray()[2] = "Bob";

    cout << "Point of " << duoArray->getSecondArray()[2] << " -> " << duoArray->getFirstArray()[1];

    delete duoArray;
}