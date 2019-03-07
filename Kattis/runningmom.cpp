#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

unordered_map<string,vs> AdjList;
unordered_map<string,int> status;

#define WHITE 0
#define GRAY 1
#define BLACK 2

bool cycle;

void dfs(string vertex){
        status[vertex] = GRAY;
        for(int i = 0; i < AdjList[vertex].size(); i++){
            string neighbour = AdjList[vertex][i];
            if(status[neighbour] == WHITE){
                dfs(neighbour);
            }else if(status[neighbour] == GRAY){
                cycle = true;
                break;
            }
        }
        status[vertex] = BLACK;
}


int main() {
    //freopen("test1.txt","r",stdin);
    int TC;
    string a,b,choice;
    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> a >> b;
        status[a] = WHITE;
        status[b] = WHITE;
        AdjList[a].push_back(b);
    }
    while(cin >> choice){
        cycle = false;
        dfs(choice);
        if(cycle == true){
            cout << choice << " " << "safe" << endl;
        }else{
            cout << choice << " " << "trapped" << endl;
        }
        for(auto& i : status){
            i.second = WHITE;
        }
    }

    return 0;
}