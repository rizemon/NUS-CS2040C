#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test1.txt","r",stdin);
    int TC;
    int g,m,str;
    cin >> TC;
    priority_queue<int,vector<int>,greater<int>> mecha,god;
    while(TC--){
        cin >> g >> m;
        while(g--){
            cin >> str;
            god.push(str);
        }
        while(m--){
            cin >> str;
            mecha.push(str);
        }
        while(!mecha.empty() && !god.empty()){
            if(mecha.top() <= god.top()){
                mecha.pop();
            }else{
                god.pop();
            }
        }
        if(mecha.empty()){
            cout << "Godzilla" << endl;
            while(!god.empty()){
                god.pop();
            }
        }else{
            cout << "MechaGodzilla" << endl;
            while(!mecha.empty()){
                mecha.pop();
            }
        }
    }
    

    return 0;
}