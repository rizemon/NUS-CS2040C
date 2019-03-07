#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test.txt","r",stdin);
    int TC;
    string content,token;
    vector<string> sounds;
    unordered_set<string> soundtable;
    getline(cin,content);
    TC = stoi(content);
    
    
    for(int i = 0; i < TC; i++){
        getline(cin,content);
        stringstream iss1(content);
        while(getline(iss1,token,' ')){
            sounds.push_back(token);
        }
        
        while(getline(cin,content)){
            if(content != "what does the fox say?"){
                stringstream iss2(content);
                while(getline(iss2,token,' ')){
                }
                soundtable.insert(token);
            }else{
                for(auto& j:sounds){
                    if(soundtable.find(j) == soundtable.end()){
                        cout << j << " ";
                    }
                }
                cout << endl;
                break;
            }
            
        }
        soundtable.clear();
        sounds.clear();
    }

    return 0;
}