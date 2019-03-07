#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define BLACK 1

typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> status; // [col][row]
vector<vi> dist; // [col][row]

int rr[] = {1,-1,2,-2,-2,2,-1,1};
int cc[] = {-2,-2,-1,-1,1,1,2,2};

int running_max;

void bfs(ii start){
    deque<ii> q;
    q.push_back(start);
    while(!q.empty()){
        ii curr = q.front();
        q.pop_front();
        int x,y;
        status[curr.first][curr.second] = BLACK;
        for(int i = 0; i < 8; i++){
            x = curr.first + cc[i];
            y = curr.second + rr[i];
            if(x >= 1 && x <= 8 && y >= 1 &&  y <= 8 && status[x][y] == WHITE){
                q.push_back(make_pair(x,y));
                dist[x][y] = dist[curr.first][curr.second] + 1;
                running_max = max(running_max,dist[x][y]);
            }
        }

    }
}

int main() {
    //freopen("test1.txt","r",stdin);
    int TC,r,c;
    cin >> TC;
    char col;
    while(TC--){
        running_max = 0;
        cin >> col >> r;
        c = col - 'a' + 1;
        status.assign(9,vi(9,WHITE));
        dist.assign(9,vi(9,100000));
        dist[c][r] = 0; 
        bfs(make_pair(c,r));
        cout << running_max;
        for(int i = 8; i >= 1; i--){
            for(int j = 1; j <= 8; j++){
                if(dist[j][i] == running_max){
                    col = 'a' + j - 1;
                    printf(" %c%d",col,i);
                }
            }
        }
        cout << endl;
    }
    return 0;
}