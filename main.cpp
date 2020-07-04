#include <iostream>
#include <stack>

using namespace std;

int main() {
    cout<<"Enter a string: ";
    string str;
    getline(cin, str);
    stack<char> charStack;
    for(char iterator : str)
        charStack.push(iterator);

    while (!charStack.empty()){
        cout<<charStack.top();
        charStack.pop();
    }
    return 0;
}