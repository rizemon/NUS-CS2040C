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
    int mintime = MAX;
    times[start.first][start.second] = 0 ;

    me.push({MAX,MAX});
    me.push(start);
    while(!me.empty()){
        pos curr = me.front();
        me.pop();
        if(curr.first == MAX && curr.second == MAX){
            int firecount = fires.size();
                while(firecount--){
                    pos flame = fires.front();
                    fires.pop();
                    AM[flame.first][flame.second] = '*';
                    for(int i = 0; i < 4; i++){
                        int y = flame.first + dy[i];
                        int x = flame.second + dx[i];
                        if(y >= 0 && y < h && x >= 0 && x < w){
                            if(AM[y][x] != '#' && AM[y][x] != '*'){
                                AM[y][x] = '*';
                                fires.push({y,x});
                            }
                        }
                    }
                }
            if(!me.empty()){
                me.push({MAX,MAX});
            }
            
        }else{
            AM[curr.first][curr.second] = '@';
            for(int i = 0; i < 4; i++){
                int y = curr.first + dy[i];
                int x = curr.second + dx[i];
                if(y >= 0 && x >= 0  && y < h && x < w){
                    if( times[y][x] == MAX&& AM[y][x] != '#' && AM[y][x] != '*'){
                        bool safe= true;
                        // for(int j = 0; j < 4; j++){
                        //     int newy = y +  dy[j];
                        //     int newx = x + dx[j];
                        //     if(newy >= 0 && newx >= 0  && newy < h && newx < w){
                        //         if(AM[newy][newx] == '*'){
                        //             safe = false;
                        //         }
                        //     }
                        // }
                        if(safe){
                            me.push({y,x});
                        times[y][x] = times[curr.first][curr.second] + 1;
                        }
                        // me.push({y,x});
                        // times[y][x] = times[curr.first][curr.second] + 1;
                    }
                }else{
                    //cout << (times[curr.first][curr.second] + 1) << endl;
                    mintime = min(mintime,times[curr.first][curr.second] + 1);
                    cout << times[curr.first][curr.second] +1 <<endl;
                    return;
                }
            }
        } 
    }
    if(mintime ==MAX){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << mintime << endl;
    }
}
int main() {
    //freopen("test1.txt","r",stdin);
    int TC;
    cin >> TC;
    string line;
    while(TC--){
        cin >> w >> h;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> AM[i][j];
                if(AM[i][j] == '@'){
                    start = {i,j};
                }else if(AM[i][j] == '*'){
                    fires.push({i,j});
                }
                times[i][j] = MAX;
            }
        }
        burn();
        while(!fires.empty()){
            fires.pop();
        }
        while(!me.empty()){
            me.pop();
        }
    }
    return 0;
}