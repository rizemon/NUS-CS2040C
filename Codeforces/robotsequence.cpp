#include <bits/stdc++.h>

using namespace std;

bool move(string directions){
    int x = 0, y = 0;
    for(auto &i: directions){
        switch(i){
            case 'U':
                y += 1;
                break;
            case 'D':
                y -= 1;
                break;
            case 'R':
                x += 1;
                break;
            case 'L':
                x -= 1;
                break;
        }
    }
    if(x==0&&y==0){
        return true;
    }else{
        return false;
    }
}

int main() {
    //freopen("test1.txt","r",stdin);
    int TC,ans=0;
    cin >> TC;
    string commands;
    cin >> commands;
    for(int offset = 0; offset < TC; offset++){
        for(int length = 1; length + offset <= TC; length++){
            //cout << commands.substr(offset,length) << endl;
            if(move(commands.substr(offset,length))){
                ans++;
            }
        }
    }
    cout << ans << endl;
    

    return 0;
}