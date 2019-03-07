#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.txt","r",stdin);
    int TC,op,val;
    bool isStack, isQueue;
    stack<int> testStack;
    queue<int> testQueue;
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
        isQueue = true;

        for(auto& i: statements ){
            if(i.first == 1){
                testStack.push(i.second);
                testQueue.push(i.second);
            }else if(testStack.empty()||testQueue.empty()){
                isStack = false;
                isQueue = false;
                break;
            }else{
                if(isStack){
                    if(testStack.top()!=i.second){
                        isStack = false;    
                    }else{
                        testStack.pop();
                    } 
                }
                if(isQueue){
                    if(testQueue.front()!=i.second){
                        isQueue = false;
                    }else{
                        testQueue.pop();
                    }
                }
            }
        }
        
        while(!testStack.empty()){
            testStack.pop();
        }
        while(!testQueue.empty()){
            testQueue.pop();
        }
        statements.clear();
        
        if(isStack&&isQueue){
            cout << "not sure" << endl;
        }else if(isStack){
            cout << "stack" << endl;
        }else if(isQueue){
            cout << "queue" << endl;
        }else{
            cout << "impossible" << endl;
        }
    }
    return 0;
}