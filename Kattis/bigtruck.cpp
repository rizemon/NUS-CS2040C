#include <bits/stdc++.h>

using namespace std;

#define MAX 1e9

typedef pair<int,int> ii;

typedef vector<ii> vii;
typedef tuple<int,int,int> iii;

int main() {
    int nodes;
    cin >> nodes;
    vector<vii> AdjList(nodes,vii());
    vector<int> contents;
    vector<int> dist(nodes, MAX);
    vector<int> item(nodes, 0);
    int itemcount;
    while(nodes--) {
        cin >> itemcount;
        contents.push_back(itemcount);
    }
    int edges;
    cin >> edges;
    int u,v,w;
    while(edges--){
        cin >> u >> v >> w;
        AdjList[u-1].push_back({v-1,w});
        AdjList[v-1].push_back({u-1,w});
    }

    priority_queue<iii,vector<iii>,greater<iii>> pq;
    dist[0] = 0;
    item[0] = contents[0];
    pq.push(make_tuple(dist[0],item[0],0));

    while(!pq.empty()){
        iii curr = pq.top();
        pq.pop();
        int distance = get<0>(curr);
        int items = get<1>(curr);
        u = get<2>(curr);
        if(distance > dist[u] && items < item[u]) continue;

        for(auto&i: AdjList[u]){
            v = i.first;
            w = i.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                item[v] = item[u] + contents[v];
                pq.push(make_tuple(dist[v],item[v],v));
            }else if(dist[u] + w == dist[v]){
                item[v] = max(item[v], item[u] + contents[v]);
                pq.push(make_tuple(dist[v],item[v],v));
            }
        }
    }
    if(dist[AdjList.size() -1 ] == MAX ){
        cout << "impossible" << endl;
    }else{
        cout << dist[AdjList.size() -1 ] << " " << item[AdjList.size()-1] << endl;
    }

    return 0;
}