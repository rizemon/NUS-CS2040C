#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second < b.second){
        return true;
    }else{
        return false;
    }
}
bool compareagain(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first){
        return true;
    }else{
        return false;
    }
}

int main() {
    int TC,number;
    vector<pair<int,int>> list1;
    vector<int> list2;
    while(cin>>TC){
        if(TC == 0){
            return 0;
        }
        for(int i = 0 ; i < TC; i++){
            cin >> number;
            list1.push_back(make_pair(i,number));
        }
        sort(list1.begin(),list1.end(),compare);

        for(int i = 0 ; i < TC; i++){
            cin >> number;
            list2.push_back(number);
        }
        sort(list2.begin(),list2.end());
        for(int i = 0; i < TC; i++){
            list1[i].second = list2[i];
        }
        sort(list1.begin(),list1.end(),compareagain);
        for(auto& i: list1){
            cout << i.second << endl;
        }
        list1.clear();
        list2.clear();
        cout << endl;

    }

    return 0;
}