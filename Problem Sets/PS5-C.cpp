// Copy paste this C++ Template and save it as "Labor.cpp"
#include <bits/stdc++.h>
using namespace std;

// write your matric number here: A0159052H
// write your name here: Tan Jia Le
// write list of collaborators here:
// year 2017 Sem1 hash code: 9sCRYVKRYjb8AjeHhpg4 (do NOT delete this line)

typedef pair<int, int> ii;
typedef tuple<int,int,int> iii; //Dist,Junction,vertex
typedef vector<ii> vii;
// We set V, Q, and AdjList to be global variables so that they are directly accessible in all other methods/functions
int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vii> AdjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge

//vector<vector<ii>> dist;// dist + junctions
vector<vector<int>> dist;// [destination][numberOfVertices] = dist

#define MAX 1000000

void PreProcess() {
    //dist.assign(V,vector<int>(V,MAX));
    // Write necessary code to preprocess the graph, if needed
    //
    // write your answer here
    //------------------------------------------------------------------------- 
    //------------------------------------------------------------------------- 
}

int Query(int s, int t, int k) {
    dist.assign(V,vector<int>(V,MAX));
    int ans = -1;
    set<iii> pq;
    pq.insert(make_tuple(0,1,s));
    for(int i = 0; i < V; i++){
        dist[s][i] = 0;
        if(i != s){
            pq.insert(make_tuple(MAX,MAX,i));
        }
    }
    while(!pq.empty()){
        iii curr = *pq.begin();
        pq.erase(pq.begin());
        int curr_dist = get<0>(curr);
        int curr_junction = get<1>(curr);
        int curr_vertex = get<2>(curr);
        if(curr_junction < k ){
            for(auto& vw: AdjList[curr_vertex]){
                int v = vw.first;
                int w = vw.second;
                if(curr_dist + w < dist[v][curr_junction]){
                    pq.erase(make_tuple(dist[v][curr_junction],curr_junction,v));
                    dist[v][curr_junction] = curr_dist + w;
                    pq.insert(make_tuple(dist[v][curr_junction],curr_junction+1,v));
                }
            }
        }
    }

    int min_dist = MAX;

    for(int i = 0; i < k; i++){
        min_dist = min(min_dist,dist[t][i]);
    }
    if(min_dist != MAX){
        ans = min_dist;
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
    //freopen("test1.txt","r",stdin);
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