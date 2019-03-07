#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string,int> first, pair<string,int> second){
    return (first.second < second.second);
}

int main() {
    int tc;
    string input1, input2;
    cin >> tc;
    vector<pair<string,int>> list;
    for(int i = 0; i < tc ; i++){
        cin >> input1;
        cin >> input2;
        if(input1.at(0) >= 'a' && input1.at(0) <= 'z'){
            list.push_back(make_pair(input1,stoi(input2)*2));
        }else{
            list.push_back(make_pair(input2,stoi(input1)));
        }
    }
    sort(list.begin(),list.end(),compare);
    for(auto& i : list){
        cout << i.first << endl;
    }
    return 0;
}