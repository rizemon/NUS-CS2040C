#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    int alice = 0;
    int bob = 0;
    priority_queue<int> list;
    int num;
    while(TC--){
        cin >> num;
        list.push(num);
    }
    
    while(!list.empty()){
        if(list.size()%2 == 1){
            alice += list.top();
        }else{
            bob += list.top();
        }
        list.pop();
    }
    if(alice < bob){
        cout << bob << " " << alice << endl;
    }else{
        cout << alice << " " << bob << endl;
    }

    return 0;
}