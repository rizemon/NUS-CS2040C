#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test.txt","r",stdin);
    int TC;

    string buffer,token,name;
    map<string,vector<string>> history;
    while(true){
        getline(cin,buffer);
        if(buffer == "0"){
            break;
        }
        TC = stoi(buffer);
        for(int i = 0; i < TC; i++){
            getline(cin,buffer);
            stringstream iss(buffer);
            getline(iss,name,' ');
            while(getline(iss,token,' ')){
                history[token].push_back(name);
            }
        }
        for(auto& kv: history){
            cout << kv.first;
            sort(kv.second.begin(),kv.second.end());
            for(auto& name: kv.second){
                cout << " " << name;
            }
            cout << endl;
            kv.second.clear();
        }
        cout << endl;
        history.clear();

    }

    return 0;
}