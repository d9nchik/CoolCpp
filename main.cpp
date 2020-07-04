#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class ShowData {
public:
    void operator()(const T &element) const {
        cout << element << ", ";
    }
};

class Person {
public:
    int age;
    bool isFemale;

    bool operator<(const Person &anotherPerson) const {
        if (age != anotherPerson.age)
            return age < anotherPerson.age;
        return !isFemale || anotherPerson.isFemale;
    }
};

int main() {
    priority_queue<Person> priorityQueue;
    priorityQueue.push({25, true});
    priorityQueue.push({30, false});
    priorityQueue.push({60, false});
    priorityQueue.push({60, true});
    while (!priorityQueue.empty()) {
        Person person = priorityQueue.top();
        priorityQueue.pop();
        cout << "To post goes ";
        if (person.isFemale)
            cout << "fe";
        cout << "male with age " << person.age << endl;
    }
    return 0;
}