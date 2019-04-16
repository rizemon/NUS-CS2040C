#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pos;

set<pos> board;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2 , 2, 1, -1, -2, -2, -1};

bool checkValid(pos knight){
    for(int i = 0 ; i < 8 ; i++){
        if(board.find({knight.first + dx[i], knight.second + dy[i]}) != board.end()){
            return false;
        }
    }
    return true;
}

int main(){
    char c;
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            cin >> c;
            if(c == 'k') board.insert({x,y});
        }
    }
    if(board.size() != 9){
        cout << "invalid" << endl;
    }else{
        for(auto& i: board){
            if(!checkValid(i)){
                cout << "invalid" << endl;
                return 0;
            } 
        }
        cout << "valid" << endl;
    }   
    
    return 0;
}