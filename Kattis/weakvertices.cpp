#include <bits/stdc++.h>

using namespace std;


int main() {
    int TC;
    int AM[20][20];
    while(cin >> TC){
        if(TC == -1){
            break;
        }
        set<int> weak;
        for(int i = 0; i < TC; i++){
            for(int j = 0; j < TC; j++){
                cin >> AM[i][j];
            }
            weak.insert(i);
        }
        
        for(int k = 0; k < TC; k++){
            for(int i = 0; i < TC; i++){
                for(int j = 0; j < TC; j++){
                    if(AM[i][j] == 1 && AM[i][k] == 1 && AM[k][j] == 1){
                        weak.erase(i);
                        weak.erase(j);
                        weak.erase(k);
                    }
                }
            }
        }
        for(auto& i: weak){
            cout << i << " ";
        }
        cout << endl;
    }
    

    return 0;
}