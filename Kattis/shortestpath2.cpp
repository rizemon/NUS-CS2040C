#include <bits/stdc++.h>

using namespace std;

#define MAX 1e9

typedef pair<int,int> ii;
typedef struct{
    int vertex;
    int starttime;
    int interval;
    int traveltime;
}neighbour;

vector<vector<neighbour>> AdjList;

vector<int> timelist;

void sssp(int source,int nodes){
    timelist[source] = 0;
    set<ii> pq;
    pq.insert({0,source});
    while(!pq.empty()){
        ii curr = *pq.begin();
        pq.erase(pq.begin());
        if(curr.first > timelist[curr.second]) continue;
        //cout << curr.second << endl;
        for(auto& iiii: AdjList[curr.second]){
            if(iiii.interval == 0){
                //iiii.starttime  >= curr.first
                if(curr.first <= iiii.starttime  ){
                    timelist[iiii.vertex] = iiii.starttime + iiii.traveltime;
                }
            }else{
                int nexttime = iiii.starttime;
                while(nexttime < curr.first){
                    nexttime += iiii.interval;
                }
                nexttime += iiii.traveltime;
                if(nexttime < timelist[iiii.vertex]){
                    timelist[iiii.vertex] = nexttime;   
                    pq.insert({timelist[iiii.vertex],iiii.vertex});
                }
            }
        }
    }

}

int main() {
    //freopen("test1.txt","r",stdin);
    int nodes, edges, queries, source;
    while(cin >> nodes >> edges >> queries >> source){
        if(nodes == 0 && edges == 0 && queries == 0 && source == 0){
            break;
        }
        int v,u, starttime, interval,traveltime;

        timelist.assign(nodes,MAX);
        AdjList.assign(nodes,vector<neighbour>());

        while(edges--){
            cin >> v >> u >> starttime >> interval >> traveltime;
            AdjList[v].push_back({u,starttime,interval,traveltime});
        }
        sssp(source,nodes);
        int dest;
        while(queries--){
            cin >> dest;
            if(timelist[dest] == MAX){
                cout << "Impossible" <<endl;
            }else{
                cout << timelist[dest] << endl;
            }
        }

        cout << endl;
    }

    return 0;
}