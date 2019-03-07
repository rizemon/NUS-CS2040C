#include <bits/stdc++.h>

using namespace std;

#define MAX 1e9

int main() {
    int floors, start , end , up , down;
    cin >> floors >> start >> end >> up >> down;

    vector<int> levels(floors+1,MAX);
    levels[start] = 0;

    queue<int> q;
    q.push(start);
    int ans = MAX;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == end){
            ans = levels[curr];
        }
        int newup = curr + up;
        int newdown = curr - down;
        if(newup <= floors && levels[newup] == MAX){
            q.push(newup);
            levels[newup] = levels[curr] + 1;
        }
        if(newdown >= 1 && levels[newdown] == MAX){
            q.push(newdown);
            levels[newdown] = levels[curr] + 1;
        }
    }
    if( ans == MAX){
        cout << "use the stairs" << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}