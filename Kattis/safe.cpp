#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;

    int dy[] = {1,2,-1,-2,0,0,0,0,0};
    int dx[] = {0,0,0,0,0,1,2,-1,-2};


bool check(vvi current){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            if(current[i][j] != 0) return false;
        }
    }
    return true;
}

vvi click(vvi current,int i,int j){
    vvi copy = current;
    for(int a = 0; a < 9; a++){
        int newy = i + dy[a];
        int newx = j + dx[a];
        if(newy < 0 || newy > 2 || newx < 0 || newx > 2) continue;
        copy[newy][newx] = (copy[newy][newx] + 1)%4;
    }
    return copy;
}

string toString(vvi current){
    string output = "";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            output += to_string(current[i][j]);
        }
    }
    return output;
}

int main() {
    vvi combination(3,vector<int>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            cin >> combination[i][j];
        }
    }
    set<string> combinations;
    queue<pair<vvi,int>> q;
    q.push({combination,0});
    while(!q.empty()){
        pair<vvi,int> curr = q.front();
        vvi grid = curr.first;
        int count = curr.second;
        q.pop();
        //cout << toString(grid) << endl;
        if(check(grid)){
            cout << count << endl;
            return 0;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3;j++){
                vvi newgrid = click(grid,i,j);
                if(combinations.find(toString(newgrid)) == combinations.end()){
                    q.push({newgrid,count+1});
                    combinations.insert(toString(newgrid));
                }

            }
        }
    }
    cout << -1 << endl;


    return 0;
}