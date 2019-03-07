#include <bits/stdc++.h>

using namespace std;

#define MAX 1e9

int main() {
    int nodes, edges, queries;
    while(cin >> nodes >> edges >> queries){
        if(nodes == 0 && edges == 0 && queries == 0){
            break;
        }
        vector<vector<int>> AM;
        AM.assign(nodes,vector<int>(nodes,MAX));
        for(int i = 0; i < nodes; i++){
            AM[i][i] = 0;
        }
        int v,u,w;
        while(edges--){
            cin >> v >> u >> w;
            //AM[v][u] = w;
            AM[v][u] =min(AM[v][u], w);
        }
        for(int k = 0; k < nodes; k++){
            for(int i = 0; i < nodes; i++){
                for(int j = 0; j < nodes; j++){
                    if(AM[i][k] != MAX && AM[k][j] != MAX){
                         AM[i][j] = min(AM[i][j],AM[i][k] + AM[k][j]);
                    }
                }
            }
        }
        for (int i=0;i<nodes;i++)
			for (int j=0;j<nodes;j++)
				for (int k=0;AM[i][j]!=-MAX && k<nodes;k++)
					if (AM[k][k]<0 && AM[i][k]!=MAX && AM[k][j]!=MAX)
                        AM[i][j] = -MAX;
                        
        int source, dest;
        while(queries--){
            cin >> source >> dest;
            if(AM[source][dest] == MAX){
                cout << "Impossible" << endl;
            }else{
                if(AM[source][dest] == -MAX){
                    cout << "-Infinity" << endl;
                }else{
                    cout << AM[source][dest] << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}