#include <bits/stdc++.h>

using namespace std;
typedef pair<string,int> participant;
class maxComp{
public:
    bool operator() (participant first, participant second){
        return first.second < second.second;
    } 
};
class minComp{
public:
    bool operator() (participant first, participant second){
        return first.second > second.second;
    } 
};

typedef priority_queue<participant, vector<participant>, maxComp> region;

string result(region& r){
    priority_queue<participant, vector<participant>, minComp> shortlist;
    string output = "";
    while(!r.empty()){
        if(shortlist.size() < 2){
            shortlist.push(r.top());
            r.pop();
        }else{
            if(shortlist.top().second == r.top().second){ 
                shortlist.pop(); 
                break;
            }else{
                break;
            }
        }
    }
    if (shortlist.size() < 2 ){
        output = "?";
    }else{
        while(!shortlist.empty()){
            output = shortlist.top().first + " " + output;
            shortlist.pop();
        }
        output.pop_back();
    }
    return output;
    

}


int main() {
    //freopen("test1.txt","r",stdin);
    int n,m,r,p;
    string name;
    cin >> n >> m;
    region * regions = new region[m];
    for(int i = 0; i < n; i++){
        cin >> name >> r >> p;
        regions[r-1].push(make_pair(name,p));
    }
    for(int j = 0; j < m; j++){
        cout << result(regions[j])  << endl;
    }


    
    return 0;
}