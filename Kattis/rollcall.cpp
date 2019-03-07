#include <bits/stdc++.h>

using namespace std;
typedef pair<string,string> name;

class Compare{
public:
    bool operator() (name person1, name person2){
        if(person1.second != person2.second){
            return person1.second > person2.second;
        }else if(person1.first != person2.first){
            return person1.first > person2.first;
        }
    }  
};


int main() {
    //freopen("test1.txt","r",stdin);
    string firstname,lastname;
    priority_queue<name,vector<name>,Compare> namelist;
    multiset<string> repetitions_firstname;
    while(cin >> firstname >> lastname){
        namelist.push(make_pair(firstname,lastname));
        repetitions_firstname.insert(firstname);
    }
    while(!namelist.empty()){
        name lmao = namelist.top();
        cout << lmao.first;
        if(repetitions_firstname.count(lmao.first)> 1){
            cout << " " << lmao.second << endl;
        }else{
            cout << endl;
        }
        namelist.pop();
    }

    return 0;
}