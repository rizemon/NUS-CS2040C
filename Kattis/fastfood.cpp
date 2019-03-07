#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test1.txt","r",stdin);
    int TC;
    cin >> TC;
    while(TC--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> prizes;
        vector<int> values;
        unordered_map<int,int> stickers;
        int total = 0;
        while(n--){
            vector<int> prizetype;
            int typecount,type, value;
            cin >> typecount;
            while(typecount--){
                cin >> type;
                prizetype.push_back(type);
            }
            cin >> value;
            values.push_back(value);
            prizes.push_back(prizetype);
        }
        for(int i = 1; i <= m; i++){
            cin >> stickers[i];
        }
        for(int i = 0; i < prizes.size(); i++){

            int mini = 100;
             for(auto& j: prizes[i]){
                mini = min(mini,stickers[j]);
            }
            total += mini * values[i];
            for(auto& j: prizes[i]){
                stickers[j] -= mini;
            }
        }
        cout << total << endl;
    }

    return 0;
}