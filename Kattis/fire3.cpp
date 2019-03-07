#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

typedef pair<int,int> pos;

#define MAX 1000000

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char AM[1000][1000];
int times[1000][1000];

int w,h;
pos start;
queue<pos> fires,me;

void burn(){
    times[start.first][start.second] = 0 ;
    me.push({MAX,MAX});
    me.push(start);
    while(!me.empty()){
        pos curr = me.front();
        me.pop();
        if(curr.first == MAX && curr.second == MAX){
            int firecount = fires.size();
            if(!me.empty()){
                me.push({MAX,MAX});
                if(!fires.empty()){
                    while(firecount--){
                    pos flame = fires.front();
                    fires.pop();
                    AM[flame.first][flame.second] = 'F';
                    for(int i = 0; i < 4; i++){
                        int y = flame.first + dy[i];
                        int x = flame.second + dx[i];
                        if(y >= 0 && y < h && x >= 0 && x < w){
                            if(AM[y][x] != '#' && AM[y][x] != 'F'){
                                AM[y][x] = 'F';
                                fires.push({y,x});
                            }
                        }
                    }
                }
                }
            }
            
        }else{
            AM[curr.first][curr.second] = 'J';
            for(int i = 0; i < 4; i++){
                int y = curr.first + dy[i];
                int x = curr.second + dx[i];
                if(y >= 0 && x >= 0  && y < h && x < w){
                    if(times[y][x] == MAX && AM[y][x] != '#' && AM[y][x] != 'F'){
                        bool safe = true;
                        // for(int j = 0; j < 4; j++){
                        //     int newy = y +  dy[j];
                        //     int newx = x + dx[j];
                        //     if(newy >= 0 && newx >= 0  && newy < h && newx < w){
                        //         if(AM[newy][newx] == 'F'){
                        //             safe = false;
                        //         }
                        //     }
                        // }
                        if(safe){
                            me.push({y,x});
                            times[y][x] = times[curr.first][curr.second] + 1;
                        }
                    }
                }else{
                    cout << times[curr.first][curr.second] + 1 << endl;
                    return;
                }
            }
        } 
    }
    cout << "IMPOSSIBLE" << endl;
}
int main() {
    //freopen("test1.txt","r",stdin);
    string line;
        cin >> h >> w;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> AM[i][j];
                if(AM[i][j] == 'J'){
                    start = {i,j};
                }else if(AM[i][j] == 'F'){
                    fires.push({i,j});
                }
                times[i][j] = MAX;
            }
        }
        burn();
        
    return 0;
}