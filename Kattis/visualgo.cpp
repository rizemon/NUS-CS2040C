#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000000

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dist;
vi ways;

int sssp(int s, int t){
    priority_queue<ii,vii,greater<ii>> pq;
    pq.push({0,s});
    dist[s] = 0;
    ways[s] = 1;
    while(!pq.empty()){
        ii front = pq.top();
        pq.pop();
        int d = front.first;
        int v = front.second;
        if (d > dist[v]) continue;
        for(auto& neighbour: AdjList[v]){
            if(dist[v] + neighbour.second < dist[neighbour.first]){
                dist[neighbour.first] = dist[v] + neighbour.second;
                pq.push({dist[neighbour.first],neighbour.first});
                ways[neighbour.first] = ways[v];
            }else if(dist[v] + neighbour.second == dist[neighbour.first]){
                ways[neighbour.first] += ways[v];
            }
        }
    }
    return ways[t];
}

int main() {
    //freopen("test1.txt","r",stdin);
    int V,E;
    cin >> V >> E;
    int u,v,w;
    AdjList.assign(V,vii());
    dist.assign(V,MAX);
    ways.assign(V,0);
    while(E--){
        cin >> u >> v >> w;
        AdjList[u].push_back({v,w});
    }
    cin >> u >> w;
    cout << sssp(u,w) << endl;

    return 0;
}