#include <bits/stdc++.h>

using namespace std;

bool compare(string name1, string name2){
    if(name1.at(0)!=name2.at(0)){
        return (name1.at(0)<name2.at(0));
    }else if(name1.at(1)!=name2.at(1)){
        return (name1.at(1)<name2.at(1));
    }else{
        return false;
    }
}

void printList(vector<string> &list){
    for(auto& i: list){
        cout << i << endl;
    }
}

int main() {
    int number;
    string name;
    vector<vector<string>> list;
    int j;
    for(j = 0;;j++){
        vector<string> names;
        cin >> number;
        if(number == 0){
            break;
        }
        for(int i = 0; i < number; i++){
            cin >> name;
            names.push_back(name);
        }
        stable_sort(names.begin(),names.end(),compare);
        list.push_back(names);
    }
    if(j >= 0){
        printList(list.at(0));
        for(int i = 1; i < list.size(); i++){
            cout << endl;
            printList(list.at(i));
        }
    }
    return 0;
}