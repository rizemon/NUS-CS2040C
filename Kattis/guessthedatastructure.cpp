#include <bits/stdc++.h>

using namespace std;

int main(){
    int lines;
    while(cin >> lines){
        int com, x;
        bool isStack = true, isQueue = true, isHeap = true;
        stack<int> ds1;
        queue<int> ds2;
        priority_queue<int> ds3;
        while(lines--){
            cin >> com >> x;
            if(com == 1){
                if(isStack) ds1.push(x);
                if(isQueue) ds2.push(x);
                if(isHeap) ds3.push(x);
            }else{
                if(ds1.size() > 0 && ds1.top() == x) ds1.pop();
                else isStack = false;

                if(ds2.size() > 0 && ds2.front() == x) ds2.pop();
                else isQueue = false;

                if(ds3.size() > 0 && ds3.top() == x) ds3.pop();
                else isHeap = false;
            }
        }

        int total = isStack + isQueue + isHeap;
        if(total < 1) cout << "impossible" << endl;
        else if(total == 1){
            if(isStack) cout << "stack" << endl;
            if(isQueue) cout << "queue" << endl;
            if(isHeap) cout << "priority queue" << endl;
        }else{
            cout << "not sure" << endl;
        }


    }
}