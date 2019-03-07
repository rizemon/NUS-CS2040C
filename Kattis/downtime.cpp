#include <bits/stdc++.h>

using namespace std;

#define OUT 0
#define IN 1 

typedef pair<int,int> ii;

int main() {
    int requests, perserver;
    cin >> requests >> perserver;

    int serverslot = perserver;
    int servercount = 1;
    int timestamp;
    // priority_queue< pair<int,int> > timeline

    priority_queue<ii, vector<ii>, greater<ii>> timeline;

    while(requests--){
        cin >> timestamp;
        timeline.push({timestamp, IN});
        timeline.push({timestamp+1000, OUT});
    }

    while(!timeline.empty()){
        pair<int,int> curr = timeline.top();
        timeline.pop();
        if(curr.second == OUT){
            serverslot++;
        }else{
            if(serverslot == 0){
                serverslot += perserver;
                servercount++;
            }
            serverslot--;
        }
    }
    cout << servercount << endl;



    return 0;
}