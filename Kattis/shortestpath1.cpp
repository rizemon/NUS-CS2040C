#include <bits/stdc++.h>

using namespace std;

#define MAX 10000000

typedef pair<int,int> ii;

typedef vector<ii> vii;

vector<vii> AdjList;

vector<int> dist;

void sssp(int index,int n){
    dist.assign(n,MAX);
    dist[index] = 0;
    set<ii> pq;
    pq.insert(make_pair(0,index));
    for(int i = 0; i < n ; i++ ){
        if(i != index){
            pq.insert(make_pair(MAX,i));
        }
    }
    while(!pq.empty()){
        ii curr = *pq.begin();
        pq.erase(pq.begin());
        for(auto& wv: AdjList[curr.second]){
            int v = wv.second;
            int w = wv.first;
            if(dist[curr.second]+w < dist[v]){
                pq.erase(pq.find(make_pair(dist[v],v)));
                dist[v] = dist[curr.second] + w;
                pq.insert(make_pair(dist[v],v));
            }
        }
    }
}


int main() {
    //freopen("test1.txt","r",stdin);
    int n, m, q, s;
    int u,v,w;
    while(cin >> n >> m >> q >> s){
        if(n == 0 && m == 0 && q == 0 && s  ==0){
            break;
        }
        AdjList.assign(n,vii());
        while(m--){
            cin >> u >> v >> w;
            AdjList[u].push_back(make_pair(w,v));
        }
        sssp(s,n);
        while(q--){
            cin >> v;
            if (dist[v] == MAX){
                cout << "Impossible" << endl;
            }else{
                cout << dist[v] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}