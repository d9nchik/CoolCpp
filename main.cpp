#include <iostream>
#include <memory>

using namespace std;

class Fish {
public:
    Fish() { cout << "Fish: Constructed!" << endl; }

    virtual ~Fish() { cout << "Fish: Destructed!" << endl; }

    virtual void swim() const { cout << "Fish swims in water" << endl; }
};

void makeFishSwim(const unique_ptr<Fish> &inFish) {
    inFish->swim();
}

class Carp: public Fish{
public:
    void swim() const override {
        cout<<"Carp swims in freshwater"<<endl;
    }

    ~Carp() override {
        cout<<"Carp: destructor"<<endl;
    }
};

int main() {
    unique_ptr<Fish> ptr (new Carp);
    makeFishSwim(ptr);
    return 0;
}