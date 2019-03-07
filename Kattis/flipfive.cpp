#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> vvc;

#define MAX 1e9

int dy[] = {1,-1,0,0,0};
int dx[] = {0,0,1,-1,0};

vvc click(vvc copy,int i, int j){
    vvc erm = copy;
    for(int k = 0; k < 5; k++){
        int newy = i + dy[k];
        int newx = j + dx[k];
        if(newy < 0 || newy >= 3 || newx < 0 || newx >= 3) continue;
        if(erm[newy][newx] == '.'){
            erm[newy][newx] = '*';
        }else{
            erm[newy][newx] = '.';
        }
    }

    return erm;
}

string toString(vvc copy){
    string output = "";
    for(int i = 0 ; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            output += copy[i][j];
        }
    }
    return output;
}

int main() {
    int TC;
    cin >> TC;

    vvc end(3,vector<char>(3));
    vvc start(3,vector<char>(3,'.'));

    unordered_map<string,int> yea;

    queue<pair<vvc,int>> q;
    q.push({start,0});
    while(!q.empty()){
        if(yea.size() == 512) break;
        pair<vvc,int> curr = q.front();
        q.pop();
        vvc grid = curr.first;
        int count = curr.second;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                vvc updated = click(grid,i,j);
                if(yea[toString(updated)] == 0){
                    yea[toString(updated)] = count+1;
                    q.push({updated,count+1});
                }
            }
        }
    }
    
    while(TC--){
        string choice = "";
        yea["........."] = -1;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin >> end[i][j];
                choice += end[i][j];
            }
        }
        if(choice == "........."){
            cout << 0 << endl;
        }else{
            cout << yea[choice] << endl;
        }


    }

    return 0;
}