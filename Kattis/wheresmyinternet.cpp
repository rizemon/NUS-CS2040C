#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define BLACK 1

typedef vector<int> vi;

vi status;

vector<vi> AdjList;

int notvisited;

void dfs(int vertex){
    status[vertex] = BLACK;
    notvisited--;
    for(int i = 0; i < AdjList[vertex].size();i++){
        int neighbour = AdjList[vertex][i];
        if(status[neighbour]==WHITE){
            dfs(neighbour);
        }
    }
}

int main() {
    //freopen("test1.txt","r",stdin);
    int vertices, edges, u ,v;
    cin >> vertices >> edges;
    notvisited = vertices;
    AdjList.assign(vertices+1,vi());
    status.assign(vertices+1, WHITE);
    while(edges--){
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    dfs(1);

    if(notvisited == 0){
        cout << "Connected" << endl;
    }else{
        for(int i = 1; i < status.size(); i++){
            if(status[i] == WHITE){
                cout << i << endl;
            }
        }
    }


    return 0;
}