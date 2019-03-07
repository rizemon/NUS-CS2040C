#include <bits/stdc++.h>

using namespace std;

double dist(pair<int,int> first, pair<int,int> second ){
    // if(first.first == second.first){
    //     return abs(first.second - second.second);
    // }
    // if(first.second == second.second){
    //     return abs(first.first - second.first);
    // }
    return sqrt(pow(first.first-second.first,2) + pow(first.second-second.second,2));
}

int main(){
    pair<int,int> layout[9];
    int index;
    for(int i = 0; i < 3; i++ ){
        for(int j = 0; j < 3; j++ ){
            cin >> index;
            layout[index-1] = make_pair(i,j);
        }
    }
    double total = 0;
    for(int i = 0; i < 8; i++){
        total += dist(layout[i],layout[i+1]);
    }
    cout << setprecision(11) << total << endl;
    return 0;
    
    
    
}