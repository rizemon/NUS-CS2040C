#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test.txt","r",stdin);
    int TC,op,val;
    bool isStack, isQueue, isPQueue;
    stack<int> testStack;
    queue<int> testQueue;
    priority_queue<int> testPQueue;

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
        isPQueue = true;

        for(auto& i: statements ){
            if(i.first == 1){
                testStack.push(i.second);
                testQueue.push(i.second);
                testPQueue.push(i.second);
            }else if(testStack.empty()||testQueue.empty()||testPQueue.empty()){
                isStack = false;
                isQueue = false;
                isPQueue = false;
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
                if(isPQueue){
                    if(testPQueue.top()!=i.second){
                        isPQueue = false;
                    }else{
                        testPQueue.pop();
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
        while(!testPQueue.empty()){
            testPQueue.pop();
        }
        statements.clear();
        

        if((isStack&&isQueue&&isPQueue)||(isStack&&isQueue)||(isStack&&isPQueue)||(isQueue&&isPQueue)){
            cout << "not sure" << endl;
        }else if(isStack){
            cout << "stack" << endl;
        }else if(isQueue){
            cout << "queue" << endl;
        }else if(isPQueue){
            cout << "priority queue" << endl;
        }else{
            cout << "impossible" << endl;
        }
    }
    return 0;
}