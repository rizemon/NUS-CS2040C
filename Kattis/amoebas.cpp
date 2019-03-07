#include <bits/stdc++.h>

using namespace std;

char AM[100][100];
vector<pair<int,int>> black;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int row,col;

void bfs(int r, int c){
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty()){
        pair<int,int> curr = q.front();
        AM[curr.first][curr.second] = '.';
        q.pop();
        for(int i = 0; i < 8; i++){
            int newy = curr.first + dy[i];
            int newx = curr.second + dx[i];
            if(newx < 0 || newx >= col || newy < 0 || newy >= row ) continue;
            if(AM[newy][newx] == '#'){
                q.push({newy,newx});
            }
        }
    }
}



int main() {
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> AM[i][j];
            if(AM[i][j] == '#'){
                black.push_back({i,j});
            }
        }
    }
    int count = 0;
    for(auto & i: black){
        if(AM[i.first][i.second] == '#'){
            count++;
            bfs(i.first,i.second);
        }
    }
    cout << count << endl;
    
    

    return 0;
}