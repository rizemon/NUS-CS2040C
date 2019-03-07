#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    map<int, unordered_set<string>> scores;
    unordered_map<string,int> votes;
    while(getline(cin,line)){
        if(line == "***"){
            break;
        }
        votes[line]++;
    }
    for(auto&i: votes){
        scores[i.second].insert(i.first);
    }
    unordered_set<string> winners = (*(scores.rbegin())).second;
    if(winners.size() > 1){
        cout << "Runoff!" << endl;
    }else{
        cout << *(winners.begin()) << endl;
    }


    return 0;
}