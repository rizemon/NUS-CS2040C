#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi status;

void dfs(int vertex){
    status[vertex] = 1;
    for(int i = 0; i < AdjList[vertex].size(); i++){
        int neighbour = AdjList[vertex][i];
        if(status[neighbour] != 1){
            dfs(neighbour);
        }
    }
}

int main() {
    //freopen("test1.txt","r",stdin);
    int TC, m, r, a, b, CC = 0;
    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> m;
        AdjList.assign(m,vi());
        status.assign(m,0);
        cin >> r;
        for(int j = 0; j < r; j++){
            cin >> a >> b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        for(int k = 0; k < m; k++){
            if(status[k] == 0){
                dfs(k);
                CC += 1;
            }
        }
        cout << (CC - 1) << endl;
        CC = 0;
        AdjList.clear();
        status.clear();
    }

    return 0;
}