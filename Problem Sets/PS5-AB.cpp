// Copy paste this C++ Template and save it as "Labor.cpp"
#include <bits/stdc++.h>
using namespace std;

// write your matric number here: A0159052H
// write your name here: Tan Jia Le
// write list of collaborators here:
// year 2017 Sem1 hash code: 9sCRYVKRYjb8AjeHhpg4 (do NOT delete this line)

typedef pair<int, int> ii;
typedef vector<ii> vii;
// We set V, Q, and AdjList to be global variables so that they are directly accessible in all other methods/functions
int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vector<ii>> AdjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge

vector<vector<ii>> dist;// dist + junctions
#define MAX 1000000

void PreProcess() {
    dist.assign(V,vii(V,make_pair(MAX,MAX)));


    // Write necessary code to preprocess the graph, if needed
    //
    // write your answer here
    //------------------------------------------------------------------------- 
    //------------------------------------------------------------------------- 
}

int Query(int s, int t, int k) {
    int ans = -1;
    if(dist[s][t].first == MAX){
        set<ii> pq;
        pq.insert(make_pair(0,s));
        dist[s][s].first = 0;
        dist[s][s].second = 0;
        for(int i = 0; i < V; i++){
            if(i != s){
                pq.insert(make_pair(MAX,i));
            }
        }
        while(!pq.empty()){
            ii curr = *pq.begin();
            pq.erase(pq.begin());
            if(dist[s][curr.second].second + 1 >= V){
                break;
            }
            for(auto& vw:AdjList[curr.second]){
                int w = vw.second;  
                int v = vw.first;
                if(dist[s][curr.second].first + w < dist[s][v].first){
                    pq.erase({dist[s][v].first,v});
                    dist[s][v].first = dist[s][curr.second].first + w;
                    dist[s][v].second = dist[s][curr.second].second + 1;
                    pq.insert({dist[s][v].first,v});
                }

            }
        }
    }
    if(dist[s][t].first != MAX){
        ans = dist[s][t].first;
    }
    
    // You have to report the shortest path from Steven and Grace's current position s
    // to reach their chosen hospital t, output -1 if t is not reachable from s
    // with one catch: this path cannot use more than k vertices
    //
    // write your answer here



    //------------------------------------------------------------------------- 

    return ans;
}

// You can add extra function(s) if needed
// --------------------------------------------



// --------------------------------------------

int main() {
    freopen("test1.txt","r",stdin);
    int i, j, TC, k, w, source, destination, required_k;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &V);
        // clear the graph and read in a new graph as Adjacency List
        AdjList.assign(V, vector<ii>());
        for (i = 0; i < V; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d %d", &j, &w);
            AdjList[i].emplace_back(j, w); // edge (road) weight (in minutes) is stored here
            //AdjList[j].emplace_back(i, w); // edge (road) weight (in minutes) is stored here
        }
        }
        PreProcess(); // optional
        scanf("%d", &Q);
        while (Q--) {
        scanf("%d %d %d", &source, &destination, &required_k);
        printf("%d\n", Query(source, destination, required_k));
        }
        if (TC) printf("\n");
    }
    return 0;
}