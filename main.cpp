#include<string>
#include <sstream>
#include <iostream>


using namespace std;

class DynIntegers {
    const static int DEFAULT_SIZE = 5;
    int *integers = nullptr;
    int position = 0;
    int size = 0;
    string text;
public:

    explicit DynIntegers(int size = DEFAULT_SIZE) : size(size) {
        integers = new int[size];
    }

    virtual bool add(int number) {
        if (position == size) {
            int *temp = new int[size * 2 + 1];
            for (int i = 0; i < position; ++i)
                temp[i] = integers[position];
            delete[] integers;
            integers = temp;
        }
        integers[position++] = number;
        return true;
    }

    int &operator[](int index) {
        if (index >= 0 && index < position)
            return integers[index];
    }

    DynIntegers(const DynIntegers &copySource) {
        if (copySource.integers != nullptr) {
            size = copySource.size;
            integers = new int[size];
            position = copySource.position;
            for (int i = 0; i < position; ++i)
                integers[i] = copySource.integers[i];
        }
    }

    DynIntegers &operator=(const DynIntegers &copySrc) {
        if (copySrc.integers != nullptr && this != &copySrc) {
            delete[] integers;
            size = copySrc.size;
            integers = new int[size];
            position = copySrc.position;
            for (int i = 0; i < position; ++i)
                integers[i] = copySrc.integers[i];
        }

        return *this;
    }

    DynIntegers(DynIntegers &&moveSrc) noexcept {
        if (moveSrc.integers != nullptr) {
            integers = moveSrc.integers; // take ownership i.e. 'move'
            moveSrc.integers = nullptr;// free move source
            size = moveSrc.size;
            position = moveSrc.position;
        }
    }

    DynIntegers &operator=(DynIntegers &&moveSrc) noexcept {
        if (moveSrc.integers != nullptr && this != &moveSrc) {
            delete[] integers;
            size = moveSrc.size;
            integers = moveSrc.integers;
            moveSrc.integers = nullptr;
            position = moveSrc.position;
        }

        return *this;
    }


    operator const char *() {
        ostringstream formattedDate; // assists string construction
        formattedDate << "[";
        for (int i = 0; i < position - 1; ++i) {
            formattedDate << integers[i] << ", ";
        }
        formattedDate << integers[position - 1] << "]" << endl;
        text = formattedDate.str();
        return text.c_str();
    }

    virtual ~DynIntegers() {
        delete[] integers;
    }
};

void printSecondElement(DynIntegers dynIntegers) {
    cout << dynIntegers[1] << " " << &dynIntegers << endl;
}

int main() {
    auto *dynIntegers = new DynIntegers();

    dynIntegers->add(5);
    dynIntegers->add(3);
    printSecondElement(*dynIntegers);
    cout << (*dynIntegers)[1] << dynIntegers;

    delete dynIntegers;
    return 0;
}

