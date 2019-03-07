#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define BLACK 1

typedef vector<string> vs;
unordered_map<string,vs> AdjList;
unordered_map<string,int> dist;
unordered_map<string,int> status;

int MAX_REPOST;

void dfs(string user){
    status[user] = BLACK;
    for(int i = 0; i < AdjList[user].size();i++){
        string next = AdjList[user][i];
        if(status[next]==WHITE){
            dist[next] = dist[user]+1;  
            MAX_REPOST = max(MAX_REPOST,dist[next]);
            dfs(next);
        }
    }

}


int main() {
    //freopen("test1.txt","r",stdin);
    int TC;
    string user1,reposted,user2;
    MAX_REPOST = 0;
    cin >> TC;
    while(TC--){
        cin >> user1 >> reposted >> user2;
        transform(user1.begin(),user1.end(),user1.begin(),::tolower);
        transform(user2.begin(),user2.end(),user2.begin(),::tolower);
        AdjList[user2].push_back(user1);
        dist[user1] = 1;
        dist[user2] = 1;
        status[user1] = WHITE;
        status[user2]= WHITE;
    }

    dfs("polycarp");

    cout << MAX_REPOST << endl;
    return 0;
}