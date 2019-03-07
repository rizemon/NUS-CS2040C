#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC, number;
    cin >> TC;
    map<int,int> people;
    map<int,int> numbertopos;
    int counter = 1;
    while(TC--){
        cin >> number;
        people[number]++;
        numbertopos[number] = counter++;
    }
    map<int,int>::reverse_iterator last = people.rbegin();
    while(last != people.rend()){
        if((*last).second == 1){
            break;
        }
        last++;
    }
    if(last != people.rend()){
        cout << numbertopos[(*last).first] << endl;
    }else{
        cout << "none" << endl;
    }

    return 0;
}