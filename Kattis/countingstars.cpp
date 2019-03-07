#include <bits/stdc++.h>

using namespace std;


#define WHITE 0
#define BLACK 1


typedef pair<int,int> coordinates;

#define MAXSIZE 110

int AM[MAXSIZE][MAXSIZE];
int status[MAXSIZE][MAXSIZE];

int TC,pixels;

bool ifExist(int x, int y){
    return (x >= 0 && x < pixels) && (y >= 0 && y < TC);
}

void bfs(int x,int y){
    deque<pair<int,int>> q;
    q.push_back(make_pair(x,y));
    coordinates curr;
    while(!q.empty()){
        curr = q.front();
        q.pop_front();
        status[curr.first][curr.second] = BLACK;
        if(ifExist(curr.first + 1,curr.second)){
            if(status[curr.first + 1][curr.second] == WHITE && AM[curr.first + 1][curr.second] == 1){
                q.push_front(make_pair(curr.first+1,curr.second));
            }
        }
        if(ifExist(curr.first - 1,curr.second)){
            if(status[curr.first - 1][curr.second] == WHITE && AM[curr.first - 1][curr.second] == 1){
                q.push_front(make_pair(curr.first - 1,curr.second));
            }
        }
        if(ifExist(curr.first,curr.second + 1)){
            if(status[curr.first][curr.second + 1] == WHITE && AM[curr.first][curr.second + 1] == 1){
                q.push_front(make_pair(curr.first,curr.second + 1));
            }
        }
        if(ifExist(curr.first,curr.second - 1)){
            if(status[curr.first][curr.second - 1] == WHITE && AM[curr.first][curr.second - 1] == 1){
                q.push_front(make_pair(curr.first,curr.second - 1));
            }
        }

    }

}

int main() {
    //freopen("test1.txt","r",stdin);
    char color;
    int index = 1;
    int CC = 0;
    vector<coordinates> points;
    while(cin >> TC >> pixels){
        for(int i = 0; i < TC; i++){
            for(int j = 0; j < pixels; j++){
                status[j][i] = WHITE;
                AM[j][i] = 0;
                cin >> color;
                if(color == '-'){
                    AM[j][i] = 1;
                    points.push_back(make_pair(j,i));
                }
            }
        }
        for(auto& i: points){
            if(status[i.first][i.second] == WHITE){
                bfs(i.first,i.second);
                CC+=1;
            }
        }
        cout << "Case " << index++ << ": " << CC << endl;
        CC = 0;
        points.clear();
    }
    return 0;
}