#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> integers;
    while (true){
        cout<<"Enter a number: ";
        int number;
        cin >> number;
        integers.push_back(number);
        char answer;
        cout<<"Do you want to watch element?(y, n): ";
        cin >> answer;
        if (answer=='y'){
            cout<<"Enter number of index you want to watch: ";
            int index=0;
            cin>>index;
            if (index>=0 && index<integers.size()){
                cout<<"integers["<<index<<"] = "<<integers[index]<<endl;
            } else
                cout<<"Invalid index"<<endl;
        }
        cout<<"Do you want to continue?(y, n): ";
        cin >> answer;
        if (answer!='y')
            break;
    }
    return 0;
}
