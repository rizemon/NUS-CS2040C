    #include <bits/stdc++.h>

    using namespace std;

    #define MAX 1e9 

    typedef pair<int,int> ii;

    typedef vector<ii> vii;

    int main() {
        int nodes, edges, queries, source;
        while(cin >> nodes >> edges >> queries >> source){
            if(nodes == 0 && edges == 0 && queries == 0 && source == 0){
                break;
            }
            vector<vii> AdjList(nodes,vii());
            vector<int> dist(nodes,MAX);
            int u,v,w;  
            while(edges--){
                cin >> u >> v >> w;
                AdjList[u].push_back({v,w});
            }
            dist[source] = 0;
            for(int j = 0; j < nodes-1; j++ ){
                for(int k = 0; k < nodes; k++){
                    for(auto& i: AdjList[k]){
                        if(dist[k] + i.second < dist[i.first]  && dist[k] != MAX){
                            dist[i.first] = dist[k] + i.second;
                        }
                    }
                }
            }
            for(int j =0; j< nodes-1; j++){
                for(int k = 0; k < nodes; k++){
                    for(auto& i: AdjList[k]){
                        if(dist[k] == -MAX){
                            dist[i.first] = -MAX;
                        }else{
                            if(dist[k] + i.second < dist[i.first] && dist[k] != MAX){
                                dist[i.first] = -MAX;
                            }
                        }
                    }
                }
            }

            int dest;
            while(queries--){
                cin >> dest;
                if(dist[dest] == MAX){
                    cout << "Impossible" << endl;
                }else{
                    if(dist[dest] == -MAX){
                        cout << "-Infinity" << endl;
                    }else{
                        cout << dist[dest] << endl;
                    }
                }
            }
            cout << endl;
        }
        

        return 0;
    }