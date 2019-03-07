#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,T,task;
    cin >> n >> T;
    int number=0;
    for(int i = 0; i < n; i++){
        cin >> task;
        T = T - task;
        if(T<0){
            break;
        }else{
            number++;
        }
    }
    cout << number << endl;

    return 0;
}