#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define BLACK 1

typedef pair<int,int> vc;

typedef vector<vc> vvc;

vector<vvc> AdjList;
vector<int> status;
unordered_set<int> colors;

void dfs(int source,int target, int color){
    status[source] = BLACK;
    for(int i = 0; i < AdjList[source].size(); i++){
        vc next = AdjList[source][i];
        if(status[next.first]==WHITE && next.second == color){
            dfs(next.first,target,color);
        }
    }

}

int main() {
    //freopen("test1.txt","r",stdin);
    int vertices,edges,TC,source,target,color;
    cin >> vertices >> edges;
    AdjList.assign(vertices+1,vvc());
    status.assign(vertices+1,WHITE);
    while(edges--){ 
        cin >> source >> target >> color;
        AdjList[source].push_back(make_pair(target,color));
        AdjList[target].push_back(make_pair(source,color));
        colors.insert(color);
    }
    cin >> TC;
    int result = 0;
    while(TC--){
        cin >> source >> target;

        for(auto& i :colors){
            dfs(source,target,i);
            if(status[target] == BLACK){
                result++;
            }
            status.assign(vertices+1,WHITE);
        }
        cout << result << endl;
        result = 0;
    }
    return 0;
}