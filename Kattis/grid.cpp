#include <bits/stdc++.h>

using namespace std;


typedef vector<int> vi;

vector<vi> grid;

vector<vi> dist; // dest = junction;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int r,c;

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    dist[y][x] = 0 ;
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        for(int i = 0; i < 4 ; i++){
            int newx = curr.second + grid[curr.first][curr.second] * dx[i];
            int newy = curr.first + grid[curr.first][curr.second] * dy[i];
            if(newx >= 1 && newx <= c && newy >= 1 && newy <= r){
                if(dist[newy][newx] == -1){
                    q.push({newy,newx});
                    dist[newy][newx] = dist[curr.first][curr.second] + 1;
                }
            }
        }
    }

}

int main() {
    //freopen("test1.txt","r",stdin);
    int choice;
    grid.assign(510,vi(510,1));
    dist.assign(510,vi(510,-1));
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            scanf("%1d",&choice);
            //cout << choice;
            grid[i][j] = choice;
            //grid[i][j] = choice;
        }
    }
    bfs(1,1);
    cout << dist[r][c] << endl;

    return 0;
}