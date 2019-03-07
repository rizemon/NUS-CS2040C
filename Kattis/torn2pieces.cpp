#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define BLACK 1

typedef vector<string> vs;

unordered_map<string,unordered_set<string>> AdjList;

unordered_map<string,int> status;

stack<string> path;

unordered_map<string,string> parent;


void goback(string dest){
    if(parent[dest] == "NOONE"){
        return;
    }else{
        path.push(dest);
        goback(parent[dest]);
    }
}

void dfs(string source){
    status[source] = BLACK;
    for(auto& i: AdjList[source]){
        if(status[i] != BLACK){
            parent[i] = source;
            dfs(i);
        }
    }
}



int main() {
    //freopen("test1.txt","r",stdin);
    int TC;
    string line,source,dest;
    getline(cin,line);
    TC = stoi(line);
    while(TC--){
        getline(cin,line);
        istringstream iss(line);
        iss >> source;
        while(iss >> dest){
            AdjList[source].insert(dest);
            AdjList[dest].insert(source);
            status[source] = WHITE;
            status[dest] = WHITE;
            parent[source] = "UNKNOWN";
            parent[dest] = "UNKNOWN";
        }
    }
    cin >> source >> dest;

    parent[source] = "NOONE";
    dfs(source);

    if(status[dest] == BLACK){
        goback(dest);
        path.push(source);
        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }else{
        cout << "no route found" << endl;
    }

    return 0;
}