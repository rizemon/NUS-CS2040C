#include <bits/stdc++.h>

using namespace std;

vector<int> buses;

int dfs(int index){
    if(index + 1 >= buses.size() || buses[index+1] != buses[index] + 1 ){
        return 0;
    }
    return dfs(index+1) + 1;
}

int main() {
    int TC;
    cin >> TC;
    int num;
    while(TC--){
        cin >> num;
        buses.push_back(num);
    }
    sort(buses.begin(),buses.end());
    for(int i = 0; i < buses.size();i++){
        int chain = dfs(i);
        if(chain >= 2){
            cout << buses[i] << "-" << buses[i+chain] << " ";
            i += chain;
        }else{
            cout << buses[i] << " ";
        }
    }
    cout << endl;
    return 0;
}