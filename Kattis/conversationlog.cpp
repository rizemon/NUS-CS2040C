#include <bits/stdc++.h>

using namespace std;

typedef pair<int,string> word;

class Comp{
public:
    bool operator() (word first, word second){
        if(first.first != second.first){
            return first.first < second.first;
        }else{
            return first.second > second.second;
        }
    }
};

int main() {
    int TC;
    cin >> TC >> ws;
    int people = TC;
    unordered_map<string,unordered_set<string>> dictionary;
    unordered_map<string,int> used;
    unordered_set<string> namelist;

    priority_queue<word,vector<word>,Comp> list;

    while(TC--){
        string line, token;
        string user;
        getline(cin,line);
        istringstream iss(line);
        iss >> user;
        namelist.insert(user);
        while(iss >> token){
            dictionary[token].insert(user);
            used[token]++;
        }
    }
    for(auto& i: dictionary){
        if(i.second.size() == namelist.size()){
            list.push({used[i.first],i.first});
        }
    }


    
    if(list.empty()){
        cout << "ALL CLEAR" << endl;
        return 0;
    }
    while(!list.empty()){
        cout << list.top().second << endl;
        list.pop();
    }


    return 0;
}