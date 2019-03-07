#include <bits/stdc++.h>

using namespace std;


vector<int> dist;
vector<int> status;

#define BLACK 1
#define WHITE 0

void bfs(int source,int target){
    deque<int> q;
    q.push_back(source);
    while(!q.empty()){
        int curr = q.front();
        status[curr] = BLACK;
        //cout << curr << endl;
        if(curr == target){
            break;
        }
        q.pop_front();
        if(curr-1 > 0 && curr-1 != source  ){
            if(status[curr-1] == WHITE){
                q.push_back(curr-1);
                dist[curr-1] = min(dist[curr-1],dist[curr]+1);
            }
        }
        if(curr*2 <= target*2 && curr*2 != source){
            if(status[curr*2] == WHITE){
                q.push_back(curr*2);
                dist[curr*2] = min(dist[curr*2],dist[curr]+1);
            }
        }
    }
}


int main() {
    //freopen("test1.txt","r",stdin);
    int source,target;
    cin >> source >> target;
    dist.assign(20001,10000);
    status.assign(20001,WHITE);
    dist[source] = 0;
    bfs(source,target);
    cout << dist[target] << endl;


    return 0;
}