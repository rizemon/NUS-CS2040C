#include <bits/stdc++.h>

using namespace std;

stack<int> output;

typedef vector<int> vi;

vi parents;

void dfs(int child){
    if(parents[child] != 0){
        dfs(parents[child]);
        output.push(parents[child]);
    }
}


int main() {
    //freopen("test1.txt","r",stdin);
    int start, parent, child;
    cin >> start >> ws;
    string line;
    parents.assign(101,0);
    while(getline(cin,line)){
        istringstream iss(line);
        iss >> parent;
        while(iss >> child){
            parents[child] = parent;
        }
    }
    
    dfs(start);
    output.push(start);
    while(!output.empty()){
        cout << output.top() << " ";
        output.pop();
    }
    cout << endl;


    return 0;
}