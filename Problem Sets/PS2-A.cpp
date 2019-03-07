#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test.txt","r",stdin);
    int TC,op,val;
    bool isStack;
    stack<int> testStack;
    vector<pair<int,int>> statements;
    while(true){
        cin >> TC;
        if(TC == 0){
            return 0;
        }
        for(int i = 0; i < TC; i++){
            cin >> op;
            cin >> val;
            statements.push_back(make_pair(op,val));
        }

        isStack = true;

        for(auto& i: statements ){
            if(i.first == 1){
                testStack.push(i.second);
            }else if(testStack.empty()){
                isStack = false;
            }else{
                if(isStack){
                    if(testStack.top() != i.second){
                        isStack = false;
                    }else{
                        testStack.pop();
                    }
                }
            }
        }
        
        while(!testStack.empty()){
            testStack.pop();
        }
        statements.clear();
        
        if(isStack){
            cout << "stack" << endl;
        }else{
            cout << "impossible" << endl;
        }
    }


    return 0;
}