#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define BLACK 1

#define length 8

#define MAX 1000000

typedef vector<int> vi;
typedef pair<int,int> pos;
typedef vector<pos> vpos;

vector<vi> moves;
vector<vector<pos>> parent;
stack<pos> way;

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};

void bfs(int start_c, int start_r ){
    moves[start_c][start_r] = 0;
    queue<pos> q;
    q.push({start_c,start_r});
    while(!q.empty()){
        pos curr = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            for(int k = 1; k <= 7; k++){
                int newy = curr.first + k * dy[i];
                int newx = curr.second + k * dx[i];
                if(newy >= 1 && newy <= length && newx >= 1 && newx <= length){
                    if(moves[newy][newx] == MAX){
                        q.push({newy,newx});
                        parent[newy][newx] = {curr.first,curr.second};
                        moves[newy][newx] = moves[curr.first][curr.second] + 1;
                    }
                }
            }
    }
    }
}

void path(int start_c, int start_r){
    int parent_c = parent[start_c][start_r].first;
    int parent_r = parent[start_c][start_r].second;
    if(parent_c == 0 && parent_r == 0){
        return;
    }else{
        way.push({start_c,start_r});
        path(parent_c,parent_r);
    }
}

int main() {
    //freopen("test1.txt","r",stdin);
    int TC;
    char col;
    int source_r, source_c;
    int dest_r,dest_c;
    cin >> TC;
    while(TC--){
        moves.assign(length+1,vi(length+1,MAX));
        parent.assign(length+1,vpos(length+1,{0,0}));
        cin >> col >> source_r;
        source_c = col - 'A' + 1;
        bfs(source_c,source_r);
        cin >> col >> dest_r;
        dest_c = col - 'A' + 1;
        if(moves[dest_c][dest_r] != MAX ){
            path(dest_c,dest_r);
            cout << way.size();
            way.push({source_c,source_r});
            while(!way.empty()){
                pos curr = way.top();
                way.pop();
                cout << " " << char('A' - 1 + curr.first) << " " << curr.second;
            }
            cout << endl;
        }else{
            cout << "Impossible" << endl;
        }
        while(!way.empty()){
            way.pop();
        }
    }

    return 0;
}